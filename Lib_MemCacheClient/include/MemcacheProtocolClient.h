#ifndef _MEMCACHE_PROTOCOL_CLIENT_
#define _MEMCACHE_PROTOCOL_CLIENT_

/* @type head file
* @brief ���� memcached Э��Ŀͻ��˷�װ�������� memcached �� kestrel
*
* @history
*  V1.0.1 yeyzh "���ÿͻ���ʧ������ʱ��Ϊ 1s"
*  V1.0  yeyzh "���� MemCacheClient ����ʵ�ֿ�ƽ̨ memcached �ͻ��˷�װ" 
*/

#include <string>
#include <map>
#include <stdexcept>

#include <boost/thread.hpp>
#include <boost/noncopyable.hpp>

#include <MemCacheClient.h>


class MemcacheProtocolClient : private boost::noncopyable
{
public:
    /*! @brief Result code for requests to a server. 

        Success codes are greater or equal to 0. 
        Failure codes are less than 0. 
     */
    enum enum_Result { 
        // success: n >= 0
        OK        = 0,    //!< Success
        NOREPLY   = 1,    //!< Success assumed (no reply requested)
        NOTSTORED = 2,    //!< Success but item not stored (see memcached docs)
        NOTFOUND  = 3,    //!< Success but item not found (see memcached docs)

        // failure: n < 0
        NOSERVER  = -1    //!< Failure, connection error with server
    };

    /**
    * @brief ���캯��
    *
    * @param [in] _host Memcache ��������ַ
    * @param [in] _port Mecchahe �����������˿�
    *
    * @throw std::bad_alloc �ڲ� MemCacheClient ��Ա��̬�����ڴ�ʧ��
    * @throw std::runtime_error δ֪�쳣
    * @throw std::exception MemCacheClient �ڲ��쳣
    */
    MemcacheProtocolClient();

    virtual ~MemcacheProtocolClient();

    std::string &GetErrorMsg(int _errorCode)
    {
        return m_cErrorCode2Msg.find(_errorCode)->second;
    }

    // ��������ʱ�䣬��λ ms
    void SetReconnectPeriod(size_t _ms)
    {
        m_cMemCacheClientPtr->SetRetryPeriod(_ms);
    }

    /**
    * @brief Set ����
    *
    * @param [in] _key ��Ҫ Set ������ Key-Value �Ե� Key
    * @param [in] _data ���� Value ���ַ��� 
    * @param [in] _size Value �ַ����ĳ���
    *
    * @return �μ� enum_Result ����
    *
    * @throw std::exception MemCacheClient �ڲ��쳣
    * @throw std::runtime_error δ֪�쳣
    */
    int Set(const std::string &_key, const char *_data, size_t _size);

    // ����ͬ��
    int Set(const std::string &_key, const std::string &_value)
    {
        return Set(_key, _value.c_str(), _value.length());
    }

    /**
    * @brief ��ȡ _key ��Ӧ�� value_ ֵ
    * @return  �μ� enum_Result ����
    *
    * @throw std::exception MemCacheClient �ڲ��׳����쳣
    * @throw std::runtime_error δ֪�쳣
    *
    */
    int Get(const std::string &_key, std::string &value_);


    /**
    * @brief ��� Memcache ������
    *
    * @return ��ӳɹ���true�����ʧ�ܣ�false
    *
    * @throw std::invalid_argument �ڲ� MemCacheClient ��Ա��Ч
    * @throw std::exception MemCacheClient �ڲ��׳����쳣
    * @throw std::runtime_error δ֪�쳣
    *
    * ������ֻ�ж� _host �� _port �Ĺ淶�ԣ��ͷ���˵Ŀ������޹ء�
    */
    bool AddServer(const std::string &_host, const std::string &_port);


    /**
    * @brief ɾ������ Memcached ����������
    *
    * @throw std::invalid_argument �ڲ� MemcacheClient ��Ա��Ч
    * @throw std::exception MemCacheClient �ڲ��׳����쳣
    * @throw std::runtime_error δ֪�쳣
    *
    */
    void RemoveAllServer();

protected:
    std::auto_ptr<MemCacheClient> m_cMemCacheClientPtr;
    std::map<int, std::string> m_cErrorCode2Msg;
    boost::mutex m_cMutex;
};


#endif // _MEMCACHE_PROTOCOL_CLIENT_


