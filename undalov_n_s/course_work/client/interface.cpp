#include "interface.h"

Interface::Interface(ClientController* cont)
{
  connect(this, SIGNAL(GetListOfFilesReqSignal()), cont, SLOT(GetListOfFilesReq()));
  connect(this, SIGNAL(UploadFileReqSignal(QString)), cont, SLOT(UploadFileReq(QString)));
  connect(this, SIGNAL(DownloadFileReqSignal(QString)), cont, SLOT(DownloadFileReq(QString)));
}



Interface::~Interface()
{
}



void Interface::GetListOfFilesReq()
{
  emit GetListOfFilesReqSignal();
}



void Interface::UploadFileReq(QString fileName)
{
  emit UploadFileReqSignal(fileName);
}



void Interface::DownloadFileReq(QString fileName)
{
  emit DownloadFileReqSignal(fileName);
}


