#ifndef _IDL_DATAWRITER_H_INCLUDED_
#define _IDL_DATAWRITER_H_INCLUDED_
#include "include/ReturnCode.h"
#include "include/BasicTypes.h"
#include "include/DDS/DomainParticipantFactory.h"
#include "include/DDS/Topic.h"
#include "include/DDS/Publisher.h"
#include "include/DDS/DataWriter.h"
#include "IDL_UserDataType.h"
class DataWriterImpl;

class UserDataTypeDataWriter : public DataWriter
{
public:
	UserDataTypeDataWriter(DataWriterImpl* pDataWriterImpl);

	~UserDataTypeDataWriter();

	static UserDataTypeDataWriter* narrow(DataWriter* pDataWriter);

	ReturnCode_t write(UserDataType& data,const InstanceHandle_t & handle);

	ReturnCode_t write_w_timestamp(UserDataType& data,const InstanceHandle_t & handle, const Time_t& timestamp);

};

#endif
