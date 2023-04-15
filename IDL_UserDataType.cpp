// Don't modify this file as it will be overwritten.
//
#include "IDL_UserDataType.h"

UserDataType::UserDataType(const UserDataType &IDL_s){
  color = IDL_s.color;
  data = IDL_s.data;
  num = IDL_s.num;
}

UserDataType& UserDataType::operator= (const UserDataType &IDL_s){
  if (this == &IDL_s) return *this;
  color = IDL_s.color;
  data = IDL_s.data;
  num = IDL_s.num;
  return *this;
}

void UserDataType::Marshal(CDR *cdr) const {
  cdr->PutString(color);
  cdr->PutString(data);
  cdr->PutLong(num);
}

void UserDataType::UnMarshal(CDR *cdr){
  {
    char *IDL_str;
    char* IDL_data;
    cdr->GetString(IDL_str);
    cdr->GetString(IDL_data);
    cdr->GetLong(num);
    if(color != NULL )
    {
        delete color;
        delete data;
        color = NULL;
        data = NULL;
    }
    color = IDL_str;
    data = IDL_data;
  }
}

