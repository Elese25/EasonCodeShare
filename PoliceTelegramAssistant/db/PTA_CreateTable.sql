-- �ѷ��籨��Ϣ��
-- DROP TABLE pta_Out_TelegramInfo;
CREATE TABLE pta_Out_TelegramInfo
(
  id INTEGER PRIMARY KEY,
  telegram_id TEXT,  -- ������
  document_id TEXT,  -- �����ĺ�
  date_time TEXT,  -- ����ʱ��
  department_name TEXT,  -- ���絥λ
  title TEXT,  -- �ļ�����
  urgency_level TEXT,  -- �ȼ�
  secret_level TEXT,  -- �ܼ�
  page_number TEXT,  -- ҳ��
  operator TEXT,  -- ֵ��Ա����
  send_to_list TEXT,  -- ���ͣ����߷ָ�Ĳ������ƴ�
  copy_to_list TEXT,  -- ���ͣ����߷ָ�Ĳ������ƴ�
  copy_report_list TEXT  -- ���������߷ָ�ĳ�������
);


-- ���յ籨��Ϣ��
-- DROP TABLE pta_In_TelegramInfo;
CREATE TABLE pta_In_TelegramInfo
(
  id INTEGER PRIMARY KEY,
  telegram_id TEXT,  -- ������
  document_id TEXT,  -- �����ĺ�
  date_time TEXT,  -- ����ʱ��
  department_name TEXT,  -- ���絥λ
  title TEXT,  -- �ļ�����
  urgency_level TEXT,  -- �ȼ�
  secret_level TEXT,  -- �ܼ�
  page_number TEXT,  -- ҳ��
  operator TEXT,  -- ֵ��Ա����
  send_to_list TEXT,  -- ���ͣ����߷ָ�Ĳ������ƴ�
  copy_to_list TEXT,  -- ���ͣ����߷ָ�Ĳ������ƴ�
  copy_report_list TEXT  -- ���������߷ָ�ĳ�������
);

-- ������Ϣ��
-- DROP TABLE pta_DepartmentInfo;
CREATE TABLE pta_DepartmentInfo
(
  id INTEGER PRIMARY KEY,  -- ���ű��
  name TEXT,  -- ��������
  parent_id TEXT,  -- ��һ�����ű��
  department_id TEXT,  -- ʵ�ʲ��ű��
  ip TEXT, -- ���ŵ�IP��ַ
  port TEXT -- ���ŵĶ˿ں�
); 

-- ����Ա��Ϣ��
-- DROP TABLE pta_OperatorInfo;
CREATE TABLE pta_OperatorInfo
(
  id INTEGER,
  operator_id TEXT,  -- ����
  name TEXT,  -- ����
  department INTEGER,  -- ��������
  FOREIGN KEY(department) REFERENCES pta_DepartmentInfo(id)
);

-- ������Ϣ��
-- DROP TABLE pta_ConfigInfo;
CREATE TABLE pta_ConfigInfo
(
  my_department_name TEXT,  -- �Լ��Ĳ�������
  my_max_telegram_id TEXT,  -- ��ǰ��ʹ�õ���󷢵��ţ��硰2013112601��
  my_max_document_id TEXT,  -- ��ǰ��ʹ�õ���󷢵��ĺţ��硰X���ܷ�[2013]1�š�
  my_ip TEXT,  -- �Լ���IP��ַ
  my_port TEXT  -- �Լ��Ķ˿ں�
);