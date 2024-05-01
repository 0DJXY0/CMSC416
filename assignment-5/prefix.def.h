




/* ---------------- method closures -------------- */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Main::done_2_closure : public SDAG::Closure {
      

      done_2_closure() {
        init();
      }
      done_2_closure(CkMigrateMessage*) {
        init();
      }
            void pup(PUP::er& __p) {
        packClosure(__p);
      }
      virtual ~done_2_closure() {
      }
      PUPable_decl(SINGLE_ARG(done_2_closure));
    };
#endif /* CK_TEMPLATES_ONLY */


/* ---------------- method closures -------------- */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Prefix::receive_2_closure : public SDAG::Closure {
            std::vector<int> impl_noname_0;


      receive_2_closure() {
        init();
      }
      receive_2_closure(CkMigrateMessage*) {
        init();
      }
            std::vector<int> & getP0() { return impl_noname_0;}
      void pup(PUP::er& __p) {
        __p | impl_noname_0;
        packClosure(__p);
      }
      virtual ~receive_2_closure() {
      }
      PUPable_decl(SINGLE_ARG(receive_2_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Prefix::write_3_closure : public SDAG::Closure {
            std::string impl_noname_1;


      write_3_closure() {
        init();
      }
      write_3_closure(CkMigrateMessage*) {
        init();
      }
            std::string & getP0() { return impl_noname_1;}
      void pup(PUP::er& __p) {
        __p | impl_noname_1;
        packClosure(__p);
      }
      virtual ~write_3_closure() {
      }
      PUPable_decl(SINGLE_ARG(write_3_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Prefix::phase_4_closure : public SDAG::Closure {
            int phase;


      phase_4_closure() {
        init();
      }
      phase_4_closure(CkMigrateMessage*) {
        init();
      }
            int & getP0() { return phase;}
      void pup(PUP::er& __p) {
        __p | phase;
        packClosure(__p);
      }
      virtual ~phase_4_closure() {
      }
      PUPable_decl(SINGLE_ARG(phase_4_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Prefix::passValue_5_closure : public SDAG::Closure {
            int phase;
            int value;


      passValue_5_closure() {
        init();
      }
      passValue_5_closure(CkMigrateMessage*) {
        init();
      }
            int & getP0() { return phase;}
            int & getP1() { return value;}
      void pup(PUP::er& __p) {
        __p | phase;
        __p | value;
        packClosure(__p);
      }
      virtual ~passValue_5_closure() {
      }
      PUPable_decl(SINGLE_ARG(passValue_5_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */


/* DEFS: readonly CProxy_Main mainProxy;
 */
extern CProxy_Main mainProxy;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_mainProxy(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|mainProxy;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: readonly int numChares;
 */
extern int numChares;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_numChares(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|numChares;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: readonly CProxy_Prefix prefixArray;
 */
extern CProxy_Prefix prefixArray;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_prefixArray(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|prefixArray;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: readonly int numPhases;
 */
extern int numPhases;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_numPhases(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|numPhases;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: readonly int numDone;
 */
extern int numDone;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_numDone(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|numDone;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: mainchare Main: Chare{
Main(CkArgMsg* impl_msg);
void done();
};
 */
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_Main::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: Main(CkArgMsg* impl_msg);
 */
CkChareID CProxy_Main::ckNew(CkArgMsg* impl_msg, int impl_onPE)
{
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Main::__idx, CkIndex_Main::idx_Main_CkArgMsg(), impl_msg, &impl_ret, impl_onPE);
  return impl_ret;
}
void CProxy_Main::ckNew(CkArgMsg* impl_msg, CkChareID* pcid, int impl_onPE)
{
  CkCreateChare(CkIndex_Main::__idx, CkIndex_Main::idx_Main_CkArgMsg(), impl_msg, pcid, impl_onPE);
}

// Entry point registration function
int CkIndex_Main::reg_Main_CkArgMsg() {
  int epidx = CkRegisterEp("Main(CkArgMsg* impl_msg)",
      reinterpret_cast<CkCallFnPtr>(_call_Main_CkArgMsg), CMessage_CkArgMsg::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)CkArgMsg::ckDebugPup);
  return epidx;
}

void CkIndex_Main::_call_Main_CkArgMsg(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*>(impl_obj_void);
  new (impl_obj_void) Main((CkArgMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void done();
 */
void CProxy_Main::done(const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_done_void(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_done_void(), impl_msg, &ckGetChareID(),destPE);
  } else {
    CkSendMsg(CkIndex_Main::idx_done_void(), impl_msg, &ckGetChareID(),0);
  }
}

// Entry point registration function
int CkIndex_Main::reg_done_void() {
  int epidx = CkRegisterEp("done()",
      reinterpret_cast<CkCallFnPtr>(_call_done_void), 0, __idx, 0);
  return epidx;
}

void CkIndex_Main::_call_done_void(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*>(impl_obj_void);
  impl_obj->done();
  if(UsrToEnv(impl_msg)->isVarSysMsg() == 0)
    CkFreeSysMsg(impl_msg);
}
PUPable_def(SINGLE_ARG(Closure_Main::done_2_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_Main::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeMainChare);
  CkRegisterBase(__idx, CkIndex_Chare::__idx);
  // REG: Main(CkArgMsg* impl_msg);
  idx_Main_CkArgMsg();
  CkRegisterMainChare(__idx, idx_Main_CkArgMsg());

  // REG: void done();
  idx_done_void();

}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: array Prefix: ArrayElement{
Prefix();
void receive(const std::vector<int> &impl_noname_0);
void write(const std::string &impl_noname_1);
void phase(int phase);
void passValue(int phase, int value);
Prefix(CkMigrateMessage* impl_msg);
};
 */
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_Prefix::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CProxySection_Prefix::contribute(CkSectionInfo &sid, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(sid, userData, fragSize);
}

void CProxySection_Prefix::contribute(int dataSize,void *data,CkReduction::reducerType type, CkSectionInfo &sid, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(dataSize, data, type, sid, userData, fragSize);
}

template <typename T>
void CProxySection_Prefix::contribute(std::vector<T> &data, CkReduction::reducerType type, CkSectionInfo &sid, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(data, type, sid, userData, fragSize);
}

void CProxySection_Prefix::contribute(CkSectionInfo &sid, const CkCallback &cb, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(sid, cb, userData, fragSize);
}

void CProxySection_Prefix::contribute(int dataSize,void *data,CkReduction::reducerType type, CkSectionInfo &sid, const CkCallback &cb, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(dataSize, data, type, sid, cb, userData, fragSize);
}

template <typename T>
void CProxySection_Prefix::contribute(std::vector<T> &data, CkReduction::reducerType type, CkSectionInfo &sid, const CkCallback &cb, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(data, type, sid, cb, userData, fragSize);
}

#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: Prefix();
 */
void CProxyElement_Prefix::insert(int onPE, const CkEntryOptions *impl_e_opts)
{ 
   void *impl_msg = CkAllocSysMsg(impl_e_opts);
   UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
   ckInsert((CkArrayMessage *)impl_msg,CkIndex_Prefix::idx_Prefix_void(),onPE);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void receive(const std::vector<int> &impl_noname_0);
 */
void CProxyElement_Prefix::receive(const std::vector<int> &impl_noname_0, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const std::vector<int> &impl_noname_0
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<std::vector<int>>::type>::type &)impl_noname_0;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<std::vector<int>>::type>::type &)impl_noname_0;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Prefix::idx_receive_marshall2(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void write(const std::string &impl_noname_1);
 */
void CProxyElement_Prefix::write(const std::string &impl_noname_1, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const std::string &impl_noname_1
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<std::string>::type>::type &)impl_noname_1;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<std::string>::type>::type &)impl_noname_1;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Prefix::idx_write_marshall3(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void phase(int phase);
 */
void CProxyElement_Prefix::phase(int phase, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int phase
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|phase;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|phase;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Prefix::idx_phase_marshall4(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void passValue(int phase, int value);
 */
void CProxyElement_Prefix::passValue(int phase, int value, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int phase, int value
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|phase;
    implP|value;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|phase;
    implP|value;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Prefix::idx_passValue_marshall5(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Prefix(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Prefix();
 */
CkArrayID CProxy_Prefix::ckNew(const CkArrayOptions &opts, const CkEntryOptions *impl_e_opts)
{
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkArrayID gId = ckCreateArray((CkArrayMessage *)impl_msg, CkIndex_Prefix::idx_Prefix_void(), opts);
  return gId;
}
void CProxy_Prefix::ckNew(const CkArrayOptions &opts, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts)
{
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkSendAsyncCreateArray(CkIndex_Prefix::idx_Prefix_void(), _ck_array_creation_cb, opts, impl_msg);
}
CkArrayID CProxy_Prefix::ckNew(const int s1, const CkEntryOptions *impl_e_opts)
{
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  CkArrayOptions opts(s1);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkArrayID gId = ckCreateArray((CkArrayMessage *)impl_msg, CkIndex_Prefix::idx_Prefix_void(), opts);
  return gId;
}
void CProxy_Prefix::ckNew(const int s1, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts)
{
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  CkArrayOptions opts(s1);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkSendAsyncCreateArray(CkIndex_Prefix::idx_Prefix_void(), _ck_array_creation_cb, opts, impl_msg);
}

// Entry point registration function
int CkIndex_Prefix::reg_Prefix_void() {
  int epidx = CkRegisterEp("Prefix()",
      reinterpret_cast<CkCallFnPtr>(_call_Prefix_void), 0, __idx, 0);
  return epidx;
}

void CkIndex_Prefix::_call_Prefix_void(void* impl_msg, void* impl_obj_void)
{
  Prefix* impl_obj = static_cast<Prefix*>(impl_obj_void);
  new (impl_obj_void) Prefix();
  if(UsrToEnv(impl_msg)->isVarSysMsg() == 0)
    CkFreeSysMsg(impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void receive(const std::vector<int> &impl_noname_0);
 */
void CProxy_Prefix::receive(const std::vector<int> &impl_noname_0, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const std::vector<int> &impl_noname_0
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<std::vector<int>>::type>::type &)impl_noname_0;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<std::vector<int>>::type>::type &)impl_noname_0;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Prefix::idx_receive_marshall2(),0);
}

// Entry point registration function
int CkIndex_Prefix::reg_receive_marshall2() {
  int epidx = CkRegisterEp("receive(const std::vector<int> &impl_noname_0)",
      reinterpret_cast<CkCallFnPtr>(_call_receive_marshall2), CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_receive_marshall2);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_receive_marshall2);

  return epidx;
}

void CkIndex_Prefix::_call_receive_marshall2(void* impl_msg, void* impl_obj_void)
{
  Prefix* impl_obj = static_cast<Prefix*>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: const std::vector<int> &impl_noname_0*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<std::vector<int>> impl_noname_0;
  implP|impl_noname_0;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->receive(std::move(impl_noname_0.t));
}
int CkIndex_Prefix::_callmarshall_receive_marshall2(char* impl_buf, void* impl_obj_void) {
  Prefix* impl_obj = static_cast<Prefix*>(impl_obj_void);
  envelope *env = UsrToEnv(impl_buf);
  /*Unmarshall pup'd fields: const std::vector<int> &impl_noname_0*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<std::vector<int>> impl_noname_0;
  implP|impl_noname_0;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->receive(std::move(impl_noname_0.t));
  return implP.size();
}
void CkIndex_Prefix::_marshallmessagepup_receive_marshall2(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: const std::vector<int> &impl_noname_0*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<std::vector<int>> impl_noname_0;
  implP|impl_noname_0;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("impl_noname_0");
  implDestP|impl_noname_0;
}
PUPable_def(SINGLE_ARG(Closure_Prefix::receive_2_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void write(const std::string &impl_noname_1);
 */
void CProxy_Prefix::write(const std::string &impl_noname_1, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const std::string &impl_noname_1
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<std::string>::type>::type &)impl_noname_1;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<std::string>::type>::type &)impl_noname_1;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Prefix::idx_write_marshall3(),0);
}

// Entry point registration function
int CkIndex_Prefix::reg_write_marshall3() {
  int epidx = CkRegisterEp("write(const std::string &impl_noname_1)",
      reinterpret_cast<CkCallFnPtr>(_call_write_marshall3), CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_write_marshall3);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_write_marshall3);

  return epidx;
}

void CkIndex_Prefix::_call_write_marshall3(void* impl_msg, void* impl_obj_void)
{
  Prefix* impl_obj = static_cast<Prefix*>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: const std::string &impl_noname_1*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<std::string> impl_noname_1;
  implP|impl_noname_1;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->write(std::move(impl_noname_1.t));
}
int CkIndex_Prefix::_callmarshall_write_marshall3(char* impl_buf, void* impl_obj_void) {
  Prefix* impl_obj = static_cast<Prefix*>(impl_obj_void);
  envelope *env = UsrToEnv(impl_buf);
  /*Unmarshall pup'd fields: const std::string &impl_noname_1*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<std::string> impl_noname_1;
  implP|impl_noname_1;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->write(std::move(impl_noname_1.t));
  return implP.size();
}
void CkIndex_Prefix::_marshallmessagepup_write_marshall3(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: const std::string &impl_noname_1*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<std::string> impl_noname_1;
  implP|impl_noname_1;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("impl_noname_1");
  implDestP|impl_noname_1;
}
PUPable_def(SINGLE_ARG(Closure_Prefix::write_3_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void phase(int phase);
 */
void CProxy_Prefix::phase(int phase, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int phase
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|phase;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|phase;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Prefix::idx_phase_marshall4(),0);
}

// Entry point registration function
int CkIndex_Prefix::reg_phase_marshall4() {
  int epidx = CkRegisterEp("phase(int phase)",
      reinterpret_cast<CkCallFnPtr>(_call_phase_marshall4), CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_phase_marshall4);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_phase_marshall4);

  return epidx;
}

void CkIndex_Prefix::_call_phase_marshall4(void* impl_msg, void* impl_obj_void)
{
  Prefix* impl_obj = static_cast<Prefix*>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: int phase*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<int> phase;
  implP|phase;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->phase(std::move(phase.t));
}
int CkIndex_Prefix::_callmarshall_phase_marshall4(char* impl_buf, void* impl_obj_void) {
  Prefix* impl_obj = static_cast<Prefix*>(impl_obj_void);
  envelope *env = UsrToEnv(impl_buf);
  /*Unmarshall pup'd fields: int phase*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<int> phase;
  implP|phase;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->phase(std::move(phase.t));
  return implP.size();
}
void CkIndex_Prefix::_marshallmessagepup_phase_marshall4(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: int phase*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<int> phase;
  implP|phase;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("phase");
  implDestP|phase;
}
PUPable_def(SINGLE_ARG(Closure_Prefix::phase_4_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void passValue(int phase, int value);
 */
void CProxy_Prefix::passValue(int phase, int value, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int phase, int value
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|phase;
    implP|value;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|phase;
    implP|value;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Prefix::idx_passValue_marshall5(),0);
}

// Entry point registration function
int CkIndex_Prefix::reg_passValue_marshall5() {
  int epidx = CkRegisterEp("passValue(int phase, int value)",
      reinterpret_cast<CkCallFnPtr>(_call_passValue_marshall5), CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_passValue_marshall5);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_passValue_marshall5);

  return epidx;
}

void CkIndex_Prefix::_call_passValue_marshall5(void* impl_msg, void* impl_obj_void)
{
  Prefix* impl_obj = static_cast<Prefix*>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: int phase, int value*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<int> phase;
  implP|phase;
  PUP::detail::TemporaryObjectHolder<int> value;
  implP|value;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->passValue(std::move(phase.t), std::move(value.t));
}
int CkIndex_Prefix::_callmarshall_passValue_marshall5(char* impl_buf, void* impl_obj_void) {
  Prefix* impl_obj = static_cast<Prefix*>(impl_obj_void);
  envelope *env = UsrToEnv(impl_buf);
  /*Unmarshall pup'd fields: int phase, int value*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<int> phase;
  implP|phase;
  PUP::detail::TemporaryObjectHolder<int> value;
  implP|value;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->passValue(std::move(phase.t), std::move(value.t));
  return implP.size();
}
void CkIndex_Prefix::_marshallmessagepup_passValue_marshall5(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: int phase, int value*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<int> phase;
  implP|phase;
  PUP::detail::TemporaryObjectHolder<int> value;
  implP|value;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("phase");
  implDestP|phase;
  if (implDestP.hasComments()) implDestP.comment("value");
  implDestP|value;
}
PUPable_def(SINGLE_ARG(Closure_Prefix::passValue_5_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Prefix(CkMigrateMessage* impl_msg);
 */

// Entry point registration function
int CkIndex_Prefix::reg_Prefix_CkMigrateMessage() {
  int epidx = CkRegisterEp("Prefix(CkMigrateMessage* impl_msg)",
      reinterpret_cast<CkCallFnPtr>(_call_Prefix_CkMigrateMessage), 0, __idx, 0);
  return epidx;
}

void CkIndex_Prefix::_call_Prefix_CkMigrateMessage(void* impl_msg, void* impl_obj_void)
{
  call_migration_constructor<Prefix> c = impl_obj_void;
  c((CkMigrateMessage*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Prefix();
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void receive(const std::vector<int> &impl_noname_0);
 */
void CProxySection_Prefix::receive(const std::vector<int> &impl_noname_0, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const std::vector<int> &impl_noname_0
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<std::vector<int>>::type>::type &)impl_noname_0;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<std::vector<int>>::type>::type &)impl_noname_0;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Prefix::idx_receive_marshall2(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void write(const std::string &impl_noname_1);
 */
void CProxySection_Prefix::write(const std::string &impl_noname_1, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const std::string &impl_noname_1
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<std::string>::type>::type &)impl_noname_1;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<std::string>::type>::type &)impl_noname_1;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Prefix::idx_write_marshall3(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void phase(int phase);
 */
void CProxySection_Prefix::phase(int phase, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int phase
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|phase;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|phase;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Prefix::idx_phase_marshall4(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void passValue(int phase, int value);
 */
void CProxySection_Prefix::passValue(int phase, int value, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int phase, int value
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|phase;
    implP|value;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|phase;
    implP|value;
  }
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Prefix::idx_passValue_marshall5(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Prefix(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_Prefix::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeArray);
  CkRegisterArrayDimensions(__idx, 1);
  CkRegisterBase(__idx, CkIndex_ArrayElement::__idx);
  // REG: Prefix();
  idx_Prefix_void();
  CkRegisterDefaultCtor(__idx, idx_Prefix_void());

  // REG: void receive(const std::vector<int> &impl_noname_0);
  idx_receive_marshall2();

  // REG: void write(const std::string &impl_noname_1);
  idx_write_marshall3();

  // REG: void phase(int phase);
  idx_phase_marshall4();

  // REG: void passValue(int phase, int value);
  idx_passValue_marshall5();

  // REG: Prefix(CkMigrateMessage* impl_msg);
  idx_Prefix_CkMigrateMessage();
  CkRegisterMigCtor(__idx, idx_Prefix_CkMigrateMessage());

}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
void _registerprefix(void)
{
  static int _done = 0; if(_done) return; _done = 1;
  CkRegisterReadonly("mainProxy","CProxy_Main",sizeof(mainProxy),(void *) &mainProxy,__xlater_roPup_mainProxy);

  CkRegisterReadonly("numChares","int",sizeof(numChares),(void *) &numChares,__xlater_roPup_numChares);

  CkRegisterReadonly("prefixArray","CProxy_Prefix",sizeof(prefixArray),(void *) &prefixArray,__xlater_roPup_prefixArray);

  CkRegisterReadonly("numPhases","int",sizeof(numPhases),(void *) &numPhases,__xlater_roPup_numPhases);

  CkRegisterReadonly("numDone","int",sizeof(numDone),(void *) &numDone,__xlater_roPup_numDone);

/* REG: mainchare Main: Chare{
Main(CkArgMsg* impl_msg);
void done();
};
*/
  CkIndex_Main::__register("Main", sizeof(Main));

/* REG: array Prefix: ArrayElement{
Prefix();
void receive(const std::vector<int> &impl_noname_0);
void write(const std::string &impl_noname_1);
void phase(int phase);
void passValue(int phase, int value);
Prefix(CkMigrateMessage* impl_msg);
};
*/
  CkIndex_Prefix::__register("Prefix", sizeof(Prefix));

}
extern "C" void CkRegisterMainModule(void) {
  _registerprefix();
}
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
template <>
void CBase_Main::virtual_pup(PUP::er &p) {
    recursive_pup<Main>(dynamic_cast<Main*>(this), p);
}
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
template <>
void CBase_Prefix::virtual_pup(PUP::er &p) {
    recursive_pup<Prefix>(dynamic_cast<Prefix*>(this), p);
}
#endif /* CK_TEMPLATES_ONLY */
