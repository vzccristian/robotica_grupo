// **********************************************************************
//
// Copyright (c) 2003-2013 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************
//
// Ice version 3.5.1
//
// <auto-generated>
//
// Generated from file `GenericBase.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#include <GenericBase.h>
#include <Ice/LocalException.h>
#include <Ice/ObjectFactory.h>
#include <Ice/BasicStream.h>
#include <Ice/Object.h>
#include <IceUtil/Iterator.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 305
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 > 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 1
#       error Ice patch level mismatch!
#   endif
#endif

namespace
{

const ::std::string __RoboCompGenericBase__GenericBase__getBaseState_name = "getBaseState";

const ::std::string __RoboCompGenericBase__GenericBase__getBasePose_name = "getBasePose";

}

namespace
{

const char* __RoboCompGenericBase__HardwareFailedException_name = "RoboCompGenericBase::HardwareFailedException";

struct __F__RoboCompGenericBase__HardwareFailedException : public ::IceInternal::UserExceptionFactory
{
    virtual void
    createAndThrow(const ::std::string&)
    {
        throw ::RoboCompGenericBase::HardwareFailedException();
    }
};

class __F__RoboCompGenericBase__HardwareFailedException__Init
{
public:

    __F__RoboCompGenericBase__HardwareFailedException__Init()
    {
        ::IceInternal::factoryTable->addExceptionFactory("::RoboCompGenericBase::HardwareFailedException", new __F__RoboCompGenericBase__HardwareFailedException);
    }

    ~__F__RoboCompGenericBase__HardwareFailedException__Init()
    {
        ::IceInternal::factoryTable->removeExceptionFactory("::RoboCompGenericBase::HardwareFailedException");
    }
};

const __F__RoboCompGenericBase__HardwareFailedException__Init __F__RoboCompGenericBase__HardwareFailedException__i;

}

RoboCompGenericBase::HardwareFailedException::HardwareFailedException(const ::std::string& __ice_what) :
    ::Ice::UserException(),
    what(__ice_what)
{
}

RoboCompGenericBase::HardwareFailedException::~HardwareFailedException() throw()
{
}

::std::string
RoboCompGenericBase::HardwareFailedException::ice_name() const
{
    return __RoboCompGenericBase__HardwareFailedException_name;
}

RoboCompGenericBase::HardwareFailedException*
RoboCompGenericBase::HardwareFailedException::ice_clone() const
{
    return new HardwareFailedException(*this);
}

void
RoboCompGenericBase::HardwareFailedException::ice_throw() const
{
    throw *this;
}

void
RoboCompGenericBase::HardwareFailedException::__writeImpl(::IceInternal::BasicStream* __os) const
{
    __os->startWriteSlice("::RoboCompGenericBase::HardwareFailedException", -1, true);
    __os->write(what);
    __os->endWriteSlice();
}

void
RoboCompGenericBase::HardwareFailedException::__readImpl(::IceInternal::BasicStream* __is)
{
    __is->startReadSlice();
    __is->read(what);
    __is->endReadSlice();
}

namespace Ice
{
}
::IceProxy::Ice::Object* ::IceProxy::RoboCompGenericBase::upCast(::IceProxy::RoboCompGenericBase::GenericBase* p) { return p; }

void
::IceProxy::RoboCompGenericBase::__read(::IceInternal::BasicStream* __is, ::IceInternal::ProxyHandle< ::IceProxy::RoboCompGenericBase::GenericBase>& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::RoboCompGenericBase::GenericBase;
        v->__copyFrom(proxy);
    }
}

void
IceProxy::RoboCompGenericBase::GenericBase::getBaseState(::RoboCompGenericBase::TBaseState& state, const ::Ice::Context* __ctx)
{
    ::IceInternal::InvocationObserver __observer(this, __RoboCompGenericBase__GenericBase__getBaseState_name, __ctx);
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__RoboCompGenericBase__GenericBase__getBaseState_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::RoboCompGenericBase::GenericBase* __del = dynamic_cast< ::IceDelegate::RoboCompGenericBase::GenericBase*>(__delBase.get());
            __del->getBaseState(state, __ctx, __observer);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, __observer);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, true, __cnt, __observer);
        }
    }
}

::Ice::AsyncResultPtr
IceProxy::RoboCompGenericBase::GenericBase::begin_getBaseState(const ::Ice::Context* __ctx, const ::IceInternal::CallbackBasePtr& __del, const ::Ice::LocalObjectPtr& __cookie)
{
    __checkAsyncTwowayOnly(__RoboCompGenericBase__GenericBase__getBaseState_name);
    ::IceInternal::OutgoingAsyncPtr __result = new ::IceInternal::OutgoingAsync(this, __RoboCompGenericBase__GenericBase__getBaseState_name, __del, __cookie);
    try
    {
        __result->__prepare(__RoboCompGenericBase__GenericBase__getBaseState_name, ::Ice::Normal, __ctx);
        __result->__writeEmptyParams();
        __result->__send(true);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __result->__exceptionAsync(__ex);
    }
    return __result;
}

void
IceProxy::RoboCompGenericBase::GenericBase::end_getBaseState(::RoboCompGenericBase::TBaseState& state, const ::Ice::AsyncResultPtr& __result)
{
    ::Ice::AsyncResult::__check(__result, this, __RoboCompGenericBase__GenericBase__getBaseState_name);
    bool __ok = __result->__wait();
    try
    {
        if(!__ok)
        {
            try
            {
                __result->__throwUserException();
            }
            catch(const ::RoboCompGenericBase::HardwareFailedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::IceInternal::BasicStream* __is = __result->__startReadParams();
        __is->read(state);
        __result->__endReadParams();
    }
    catch(const ::Ice::LocalException& ex)
    {
        __result->__getObserver().failed(ex.ice_name());
        throw;
    }
}

void
IceProxy::RoboCompGenericBase::GenericBase::getBasePose(::Ice::Int& x, ::Ice::Int& z, ::Ice::Float& alpha, const ::Ice::Context* __ctx)
{
    ::IceInternal::InvocationObserver __observer(this, __RoboCompGenericBase__GenericBase__getBasePose_name, __ctx);
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__RoboCompGenericBase__GenericBase__getBasePose_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::RoboCompGenericBase::GenericBase* __del = dynamic_cast< ::IceDelegate::RoboCompGenericBase::GenericBase*>(__delBase.get());
            __del->getBasePose(x, z, alpha, __ctx, __observer);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex, __observer);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, true, __cnt, __observer);
        }
    }
}

::Ice::AsyncResultPtr
IceProxy::RoboCompGenericBase::GenericBase::begin_getBasePose(const ::Ice::Context* __ctx, const ::IceInternal::CallbackBasePtr& __del, const ::Ice::LocalObjectPtr& __cookie)
{
    __checkAsyncTwowayOnly(__RoboCompGenericBase__GenericBase__getBasePose_name);
    ::IceInternal::OutgoingAsyncPtr __result = new ::IceInternal::OutgoingAsync(this, __RoboCompGenericBase__GenericBase__getBasePose_name, __del, __cookie);
    try
    {
        __result->__prepare(__RoboCompGenericBase__GenericBase__getBasePose_name, ::Ice::Normal, __ctx);
        __result->__writeEmptyParams();
        __result->__send(true);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __result->__exceptionAsync(__ex);
    }
    return __result;
}

void
IceProxy::RoboCompGenericBase::GenericBase::end_getBasePose(::Ice::Int& x, ::Ice::Int& z, ::Ice::Float& alpha, const ::Ice::AsyncResultPtr& __result)
{
    ::Ice::AsyncResult::__check(__result, this, __RoboCompGenericBase__GenericBase__getBasePose_name);
    bool __ok = __result->__wait();
    try
    {
        if(!__ok)
        {
            try
            {
                __result->__throwUserException();
            }
            catch(const ::RoboCompGenericBase::HardwareFailedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::IceInternal::BasicStream* __is = __result->__startReadParams();
        __is->read(x);
        __is->read(z);
        __is->read(alpha);
        __result->__endReadParams();
    }
    catch(const ::Ice::LocalException& ex)
    {
        __result->__getObserver().failed(ex.ice_name());
        throw;
    }
}

const ::std::string&
IceProxy::RoboCompGenericBase::GenericBase::ice_staticId()
{
    return ::RoboCompGenericBase::GenericBase::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::RoboCompGenericBase::GenericBase::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::RoboCompGenericBase::GenericBase);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::RoboCompGenericBase::GenericBase::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::RoboCompGenericBase::GenericBase);
}

::IceProxy::Ice::Object*
IceProxy::RoboCompGenericBase::GenericBase::__newInstance() const
{
    return new GenericBase;
}

void
IceDelegateM::RoboCompGenericBase::GenericBase::getBaseState(::RoboCompGenericBase::TBaseState& state, const ::Ice::Context* __context, ::IceInternal::InvocationObserver& __observer)
{
    ::IceInternal::Outgoing __og(__handler.get(), __RoboCompGenericBase__GenericBase__getBaseState_name, ::Ice::Normal, __context, __observer);
    __og.writeEmptyParams();
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::RoboCompGenericBase::HardwareFailedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.startReadParams();
        __is->read(state);
        __og.endReadParams();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::RoboCompGenericBase::GenericBase::getBasePose(::Ice::Int& x, ::Ice::Int& z, ::Ice::Float& alpha, const ::Ice::Context* __context, ::IceInternal::InvocationObserver& __observer)
{
    ::IceInternal::Outgoing __og(__handler.get(), __RoboCompGenericBase__GenericBase__getBasePose_name, ::Ice::Normal, __context, __observer);
    __og.writeEmptyParams();
    bool __ok = __og.invoke();
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::RoboCompGenericBase::HardwareFailedException&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.startReadParams();
        __is->read(x);
        __is->read(z);
        __is->read(alpha);
        __og.endReadParams();
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateD::RoboCompGenericBase::GenericBase::getBaseState(::RoboCompGenericBase::TBaseState& state, const ::Ice::Context* __context, ::IceInternal::InvocationObserver&)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::RoboCompGenericBase::TBaseState& __p_state, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_state(__p_state)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::RoboCompGenericBase::GenericBase* servant = dynamic_cast< ::RoboCompGenericBase::GenericBase*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            try
            {
                servant->getBaseState(_m_state, _current);
                return ::Ice::DispatchOK;
            }
            catch(const ::Ice::UserException& __ex)
            {
                setUserException(__ex);
                return ::Ice::DispatchUserException;
            }
        }
        
    private:
        
        ::RoboCompGenericBase::TBaseState& _m_state;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __RoboCompGenericBase__GenericBase__getBaseState_name, ::Ice::Normal, __context);
    try
    {
        _DirectI __direct(state, __current);
        try
        {
            __direct.getServant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::RoboCompGenericBase::HardwareFailedException&)
    {
        throw;
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
}

void
IceDelegateD::RoboCompGenericBase::GenericBase::getBasePose(::Ice::Int& x, ::Ice::Int& z, ::Ice::Float& alpha, const ::Ice::Context* __context, ::IceInternal::InvocationObserver&)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::Ice::Int& __p_x, ::Ice::Int& __p_z, ::Ice::Float& __p_alpha, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _m_x(__p_x),
            _m_z(__p_z),
            _m_alpha(__p_alpha)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::RoboCompGenericBase::GenericBase* servant = dynamic_cast< ::RoboCompGenericBase::GenericBase*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            try
            {
                servant->getBasePose(_m_x, _m_z, _m_alpha, _current);
                return ::Ice::DispatchOK;
            }
            catch(const ::Ice::UserException& __ex)
            {
                setUserException(__ex);
                return ::Ice::DispatchUserException;
            }
        }
        
    private:
        
        ::Ice::Int& _m_x;
        ::Ice::Int& _m_z;
        ::Ice::Float& _m_alpha;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __RoboCompGenericBase__GenericBase__getBasePose_name, ::Ice::Normal, __context);
    try
    {
        _DirectI __direct(x, z, alpha, __current);
        try
        {
            __direct.getServant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::RoboCompGenericBase::HardwareFailedException&)
    {
        throw;
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
}

::Ice::Object* RoboCompGenericBase::upCast(::RoboCompGenericBase::GenericBase* p) { return p; }

namespace
{
const ::std::string __RoboCompGenericBase__GenericBase_ids[2] =
{
    "::Ice::Object",
    "::RoboCompGenericBase::GenericBase"
};

}

bool
RoboCompGenericBase::GenericBase::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__RoboCompGenericBase__GenericBase_ids, __RoboCompGenericBase__GenericBase_ids + 2, _s);
}

::std::vector< ::std::string>
RoboCompGenericBase::GenericBase::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__RoboCompGenericBase__GenericBase_ids[0], &__RoboCompGenericBase__GenericBase_ids[2]);
}

const ::std::string&
RoboCompGenericBase::GenericBase::ice_id(const ::Ice::Current&) const
{
    return __RoboCompGenericBase__GenericBase_ids[1];
}

const ::std::string&
RoboCompGenericBase::GenericBase::ice_staticId()
{
    return __RoboCompGenericBase__GenericBase_ids[1];
}

::Ice::DispatchStatus
RoboCompGenericBase::GenericBase::___getBaseState(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    __inS.readEmptyParams();
    ::RoboCompGenericBase::TBaseState state;
    try
    {
        getBaseState(state, __current);
        ::IceInternal::BasicStream* __os = __inS.__startWriteParams(::Ice::DefaultFormat);
        __os->write(state);
        __inS.__endWriteParams(true);
        return ::Ice::DispatchOK;
    }
    catch(const ::RoboCompGenericBase::HardwareFailedException& __ex)
    {
        __inS.__writeUserException(__ex, ::Ice::DefaultFormat);
    }
    return ::Ice::DispatchUserException;
}

::Ice::DispatchStatus
RoboCompGenericBase::GenericBase::___getBasePose(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    __inS.readEmptyParams();
    ::Ice::Int x;
    ::Ice::Int z;
    ::Ice::Float alpha;
    try
    {
        getBasePose(x, z, alpha, __current);
        ::IceInternal::BasicStream* __os = __inS.__startWriteParams(::Ice::DefaultFormat);
        __os->write(x);
        __os->write(z);
        __os->write(alpha);
        __inS.__endWriteParams(true);
        return ::Ice::DispatchOK;
    }
    catch(const ::RoboCompGenericBase::HardwareFailedException& __ex)
    {
        __inS.__writeUserException(__ex, ::Ice::DefaultFormat);
    }
    return ::Ice::DispatchUserException;
}

namespace
{
const ::std::string __RoboCompGenericBase__GenericBase_all[] =
{
    "getBasePose",
    "getBaseState",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping"
};

}

::Ice::DispatchStatus
RoboCompGenericBase::GenericBase::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< const ::std::string*, const ::std::string*> r = ::std::equal_range(__RoboCompGenericBase__GenericBase_all, __RoboCompGenericBase__GenericBase_all + 6, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __RoboCompGenericBase__GenericBase_all)
    {
        case 0:
        {
            return ___getBasePose(in, current);
        }
        case 1:
        {
            return ___getBaseState(in, current);
        }
        case 2:
        {
            return ___ice_id(in, current);
        }
        case 3:
        {
            return ___ice_ids(in, current);
        }
        case 4:
        {
            return ___ice_isA(in, current);
        }
        case 5:
        {
            return ___ice_ping(in, current);
        }
    }

    assert(false);
    throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}

void
RoboCompGenericBase::GenericBase::__writeImpl(::IceInternal::BasicStream* __os) const
{
    __os->startWriteSlice(ice_staticId(), -1, true);
    __os->endWriteSlice();
}

void
RoboCompGenericBase::GenericBase::__readImpl(::IceInternal::BasicStream* __is)
{
    __is->startReadSlice();
    __is->endReadSlice();
}

void 
RoboCompGenericBase::__patch(GenericBasePtr& handle, const ::Ice::ObjectPtr& v)
{
    handle = ::RoboCompGenericBase::GenericBasePtr::dynamicCast(v);
    if(v && !handle)
    {
        IceInternal::Ex::throwUOE(::RoboCompGenericBase::GenericBase::ice_staticId(), v);
    }
}
