#ifndef _IDL_DATAREADER_H_INCLUDED_
#define _IDL_DATAREADER_H_INCLUDED_

#include "include/ReturnCode.h"
#include "include/BasicTypes.h"
#include "IDL_UserDataType.h"
#include "include/DDS/DomainParticipantFactory.h"
#include "include/DDS/Topic.h"
#include "include/DDS/Subscriber.h"
#include "include/DDS/DataReader.h"
#include "include/DDS/Listener/DataReaderListener.h"

class DataReaderImpl;

class UserDataTypeDataReader : public DataReader 
{
public:
	UserDataTypeDataReader(DataReaderImpl* pDataReaderImpl);

	~UserDataTypeDataReader();

	static UserDataTypeDataReader* narrow(DataReader* pDataReader);

	ReturnCode_t take(UserDataTypeSeq& data_values, SampleInfoSeq & sample_infos, int max_samples, SampleStateKind sample_states, ViewStateKind view_states, InstanceStateKind instance_states);

	ReturnCode_t read(UserDataTypeSeq& data_values, SampleInfoSeq & sample_infos, int max_samples, SampleStateKind sample_states, ViewStateKind view_states, InstanceStateKind instance_states);

	ReturnCode_t take_next_sample(UserDataType& receivedData, SampleInfo & sample_info);

	ReturnCode_t read_next_sample(UserDataType& receivedData, SampleInfo& sample_info);

	ReturnCode_t return_loan(UserDataTypeSeq& data_values, SampleInfoSeq& sample_infos);


};

#endif
