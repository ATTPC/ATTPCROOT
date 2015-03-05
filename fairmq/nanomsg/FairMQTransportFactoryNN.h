/********************************************************************************
 *    Copyright (C) 2014 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH    *
 *                                                                              *
 *              This software is distributed under the terms of the             * 
 *         GNU Lesser General Public Licence version 3 (LGPL) version 3,        *  
 *                  copied verbatim in the file "LICENSE"                       *
 ********************************************************************************/
/**
 * FairMQTransportFactoryNN.h
 *
 * @since 2014-01-20
 * @author: A. Rybalchenko
 */

#ifndef FAIRMQTRANSPORTFACTORYNN_H_
#define FAIRMQTRANSPORTFACTORYNN_H_

#include <vector>

#include "FairMQTransportFactory.h"
#include "FairMQMessageNN.h"
#include "FairMQSocketNN.h"
#include "FairMQPollerNN.h"

class FairMQTransportFactoryNN : public FairMQTransportFactory
{
  public:
    FairMQTransportFactoryNN();

    virtual FairMQMessage* CreateMessage();
    virtual FairMQMessage* CreateMessage(size_t size);
    virtual FairMQMessage* CreateMessage(void* data, size_t size, fairmq_free_fn *ffn = NULL, void* hint = NULL);
    virtual FairMQSocket* CreateSocket(const string& type, int num, int numIoThreads);
    virtual FairMQPoller* CreatePoller(const vector<FairMQSocket*>& inputs);

    virtual ~FairMQTransportFactoryNN() {};
};

#endif /* FAIRMQTRANSPORTFACTORYNN_H_ */
