#ifndef _MEMCACHED_CLIENT_
#define _MEMCACHED_CLIENT_

#include <boost/cstdint.hpp>

#include "MemcacheProtocolClient.h"


class MemcachedClient : public MemcacheProtocolClient
{
public:
    MemcachedClient(){}

    ~MemcachedClient(){};

    /**
    * @brief ��ȡ _key ��Ӧ�� value_ ֵ
    *
    * @param [in] _key ��Ҫ Get ������ Key-Value �Ե� Key
    * @param [out] Value ������
    * @param [out] CAS ֵ
    *
    * @return  �μ� enum_Result ����
    *
    * @throw std::exception MemCacheClient �ڲ��׳����쳣
    * @throw std::runtime_error δ֪�쳣
    *
    */
    int CasGet(const std::string &_key, std::string &value_, boost::uint64_t &cas_);

    /**
    * @brief CasSet ����
    *
    * @param [in] _key ��Ҫ Set ������ Key-Value �Ե� Key
    * @param [in] _data ���� Value ���ַ��� 
    * @param [in] _size Value �ַ����ĳ���
    * @param [in] _cas CAS ֵ
    *
    * @return Set �����ɹ���true������ʧ�ܣ�false
    *
    * @throw std::exception MemCacheClient �ڲ��쳣
    * @throw std::runtime_error δ֪�쳣
    */
    bool CasSet(const std::string &_key, const char *_data, size_t _size, boost::uint64_t _cas);

    // ͬ��
    bool CasSet(const std::string &_key, const std::string &_value, boost::uint64_t _cas)
    {
        return CasSet(_key, _value.c_str(), _value.length(), _cas);
    }
};


#endif  // _MEMCACHED_CLIENT_



