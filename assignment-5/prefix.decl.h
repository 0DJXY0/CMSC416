#ifndef _DECL_prefix_H_
#define _DECL_prefix_H_
#include "charm++.h"
#include "envelope.h"
#include <memory>
#include "sdag.h"
/* DECLS: readonly CProxy_Main mainProxy;
 */

/* DECLS: readonly int numChares;
 */

/* DECLS: readonly CProxy_Prefix prefixArray;
 */

/* DECLS: mainchare Main: Chare{
Main(CkArgMsg* impl_msg);
void done();
};
 */
 class Main;
 class CkIndex_Main;
 class CProxy_Main;
/* --------------- index object ------------------ */
class CkIndex_Main:public CkIndex_Chare{
  public:
    typedef Main local_t;
    typedef CkIndex_Main index_t;
    typedef CProxy_Main proxy_t;
    typedef CProxy_Main element_t;

    static int __idx;
    static void __register(const char *s, size_t size);
    /* DECLS: Main(CkArgMsg* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_Main_CkArgMsg();
    // Entry point index lookup
    
    inline static int idx_Main_CkArgMsg() {
      static int epidx = reg_Main_CkArgMsg();
      return epidx;
    }

    
    static int ckNew(CkArgMsg* impl_msg) { return idx_Main_CkArgMsg(); }
    
    static void _call_Main_CkArgMsg(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Main_CkArgMsg(void* impl_msg, void* impl_obj);
    /* DECLS: void done();
     */
    // Entry point registration at startup
    
    static int reg_done_void();
    // Entry point index lookup
    
    inline static int idx_done_void() {
      static int epidx = reg_done_void();
      return epidx;
    }

    
    inline static int idx_done(void (Main::*)() ) {
      return idx_done_void();
    }


    
    static int done() { return idx_done_void(); }
    
    static void _call_done_void(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_done_void(void* impl_msg, void* impl_obj);
};
/* --------------- element proxy ------------------ */
class CProxy_Main:public CProxy_Chare{
  public:
    typedef Main local_t;
    typedef CkIndex_Main index_t;
    typedef CProxy_Main proxy_t;
    typedef CProxy_Main element_t;

    CProxy_Main(void) {};
    CProxy_Main(CkChareID __cid) : CProxy_Chare(__cid){  }
    CProxy_Main(const Chare *c) : CProxy_Chare(c){  }

    int ckIsDelegated(void) const
    { return CProxy_Chare::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxy_Chare::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxy_Chare::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxy_Chare::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxy_Chare::ckCheck(); }
    const CkChareID &ckGetChareID(void) const
    { return CProxy_Chare::ckGetChareID(); }
    operator const CkChareID &(void) const
    { return ckGetChareID(); }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxy_Chare::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxy_Chare::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxy_Chare::pup(p);
    }

    void ckSetChareID(const CkChareID &c)
    {      CProxy_Chare::ckSetChareID(c); }
    Main *ckLocal(void) const
    { return (Main *)CkLocalChare(&ckGetChareID()); }
/* DECLS: Main(CkArgMsg* impl_msg);
 */
    static CkChareID ckNew(CkArgMsg* impl_msg, int onPE=CK_PE_ANY);
    static void ckNew(CkArgMsg* impl_msg, CkChareID* pcid, int onPE=CK_PE_ANY);

/* DECLS: void done();
 */
    
    void done(const CkEntryOptions *impl_e_opts=NULL);

};
#define Main_SDAG_CODE 
typedef CBaseT1<Chare, CProxy_Main>CBase_Main;

/* DECLS: array Prefix: ArrayElement{
Prefix(const std::vector<int> &impl_noname_0);
void phase(int phase);
void passValue(int phase, int value);
Prefix(CkMigrateMessage* impl_msg);
};
 */
 class Prefix;
 class CkIndex_Prefix;
 class CProxy_Prefix;
 class CProxyElement_Prefix;
 class CProxySection_Prefix;
/* --------------- index object ------------------ */
class CkIndex_Prefix:public CkIndex_ArrayElement{
  public:
    typedef Prefix local_t;
    typedef CkIndex_Prefix index_t;
    typedef CProxy_Prefix proxy_t;
    typedef CProxyElement_Prefix element_t;
    typedef CProxySection_Prefix section_t;

    static int __idx;
    static void __register(const char *s, size_t size);
    /* DECLS: Prefix(const std::vector<int> &impl_noname_0);
     */
    // Entry point registration at startup
    
    static int reg_Prefix_marshall1();
    // Entry point index lookup
    
    inline static int idx_Prefix_marshall1() {
      static int epidx = reg_Prefix_marshall1();
      return epidx;
    }

    
    static int ckNew(const std::vector<int> &impl_noname_0) { return idx_Prefix_marshall1(); }
    
    static void _call_Prefix_marshall1(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Prefix_marshall1(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_Prefix_marshall1(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_Prefix_marshall1(PUP::er &p,void *msg);
    /* DECLS: void phase(int phase);
     */
    // Entry point registration at startup
    
    static int reg_phase_marshall2();
    // Entry point index lookup
    
    inline static int idx_phase_marshall2() {
      static int epidx = reg_phase_marshall2();
      return epidx;
    }

    
    inline static int idx_phase(void (Prefix::*)(int phase) ) {
      return idx_phase_marshall2();
    }


    
    static int phase(int phase) { return idx_phase_marshall2(); }
    
    static void _call_phase_marshall2(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_phase_marshall2(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_phase_marshall2(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_phase_marshall2(PUP::er &p,void *msg);
    /* DECLS: void passValue(int phase, int value);
     */
    // Entry point registration at startup
    
    static int reg_passValue_marshall3();
    // Entry point index lookup
    
    inline static int idx_passValue_marshall3() {
      static int epidx = reg_passValue_marshall3();
      return epidx;
    }

    
    inline static int idx_passValue(void (Prefix::*)(int phase, int value) ) {
      return idx_passValue_marshall3();
    }


    
    static int passValue(int phase, int value) { return idx_passValue_marshall3(); }
    
    static void _call_passValue_marshall3(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_passValue_marshall3(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_passValue_marshall3(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_passValue_marshall3(PUP::er &p,void *msg);
    /* DECLS: Prefix(CkMigrateMessage* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_Prefix_CkMigrateMessage();
    // Entry point index lookup
    
    inline static int idx_Prefix_CkMigrateMessage() {
      static int epidx = reg_Prefix_CkMigrateMessage();
      return epidx;
    }

    
    static int ckNew(CkMigrateMessage* impl_msg) { return idx_Prefix_CkMigrateMessage(); }
    
    static void _call_Prefix_CkMigrateMessage(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Prefix_CkMigrateMessage(void* impl_msg, void* impl_obj);
};
/* --------------- element proxy ------------------ */
 class CProxyElement_Prefix : public CProxyElement_ArrayElement{
  public:
    typedef Prefix local_t;
    typedef CkIndex_Prefix index_t;
    typedef CProxy_Prefix proxy_t;
    typedef CProxyElement_Prefix element_t;
    typedef CProxySection_Prefix section_t;

    using array_index_t = CkArrayIndex1D;

    /* TRAM aggregators */

    CProxyElement_Prefix(void) {
    }
    CProxyElement_Prefix(const ArrayElement *e) : CProxyElement_ArrayElement(e){
    }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxyElement_ArrayElement::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxyElement_ArrayElement::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxyElement_ArrayElement::pup(p);
    }

    int ckIsDelegated(void) const
    { return CProxyElement_ArrayElement::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxyElement_ArrayElement::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxyElement_ArrayElement::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxyElement_ArrayElement::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxyElement_ArrayElement::ckCheck(); }
    inline operator CkArrayID () const
    { return ckGetArrayID(); }
    inline CkArrayID ckGetArrayID(void) const
    { return CProxyElement_ArrayElement::ckGetArrayID(); }
    inline CkArray *ckLocalBranch(void) const
    { return CProxyElement_ArrayElement::ckLocalBranch(); }
    inline CkLocMgr *ckLocMgr(void) const
    { return CProxyElement_ArrayElement::ckLocMgr(); }

    inline static CkArrayID ckCreateEmptyArray(CkArrayOptions opts = CkArrayOptions())
    { return CProxyElement_ArrayElement::ckCreateEmptyArray(opts); }
    inline static void ckCreateEmptyArrayAsync(CkCallback cb, CkArrayOptions opts = CkArrayOptions())
    { CProxyElement_ArrayElement::ckCreateEmptyArrayAsync(cb, opts); }
    inline static CkArrayID ckCreateArray(CkArrayMessage *m,int ctor,const CkArrayOptions &opts)
    { return CProxyElement_ArrayElement::ckCreateArray(m,ctor,opts); }
    inline void ckInsertIdx(CkArrayMessage *m,int ctor,int onPe,const CkArrayIndex &idx)
    { CProxyElement_ArrayElement::ckInsertIdx(m,ctor,onPe,idx); }
    inline void doneInserting(void)
    { CProxyElement_ArrayElement::doneInserting(); }

    inline void ckBroadcast(CkArrayMessage *m, int ep, int opts=0) const
    { CProxyElement_ArrayElement::ckBroadcast(m,ep,opts); }
    inline void setReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxyElement_ArrayElement::setReductionClient(fn,param); }
    inline void ckSetReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxyElement_ArrayElement::ckSetReductionClient(fn,param); }
    inline void ckSetReductionClient(CkCallback *cb) const
    { CProxyElement_ArrayElement::ckSetReductionClient(cb); }

    inline void ckInsert(CkArrayMessage *m,int ctor,int onPe)
    { CProxyElement_ArrayElement::ckInsert(m,ctor,onPe); }
    inline void ckSend(CkArrayMessage *m, int ep, int opts = 0) const
    { CProxyElement_ArrayElement::ckSend(m,ep,opts); }
    inline void *ckSendSync(CkArrayMessage *m, int ep) const
    { return CProxyElement_ArrayElement::ckSendSync(m,ep); }
    inline const CkArrayIndex &ckGetIndex() const
    { return CProxyElement_ArrayElement::ckGetIndex(); }

    Prefix *ckLocal(void) const
    { return (Prefix *)CProxyElement_ArrayElement::ckLocal(); }

    CProxyElement_Prefix(const CkArrayID &aid,const CkArrayIndex1D &idx,CK_DELCTOR_PARAM)
        :CProxyElement_ArrayElement(aid,idx,CK_DELCTOR_ARGS)
    {
}
    CProxyElement_Prefix(const CkArrayID &aid,const CkArrayIndex1D &idx)
        :CProxyElement_ArrayElement(aid,idx)
    {
}

    CProxyElement_Prefix(const CkArrayID &aid,const CkArrayIndex &idx,CK_DELCTOR_PARAM)
        :CProxyElement_ArrayElement(aid,idx,CK_DELCTOR_ARGS)
    {
}
    CProxyElement_Prefix(const CkArrayID &aid,const CkArrayIndex &idx)
        :CProxyElement_ArrayElement(aid,idx)
    {
}
/* DECLS: Prefix(const std::vector<int> &impl_noname_0);
 */
    
    void insert(const std::vector<int> &impl_noname_0, int onPE=-1, const CkEntryOptions *impl_e_opts=NULL);
/* DECLS: void phase(int phase);
 */
    
    void phase(int phase, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void passValue(int phase, int value);
 */
    
    void passValue(int phase, int value, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: Prefix(CkMigrateMessage* impl_msg);
 */

};
/* ---------------- collective proxy -------------- */
 class CProxy_Prefix : public CProxy_ArrayElement{
  public:
    typedef Prefix local_t;
    typedef CkIndex_Prefix index_t;
    typedef CProxy_Prefix proxy_t;
    typedef CProxyElement_Prefix element_t;
    typedef CProxySection_Prefix section_t;

    using array_index_t = CkArrayIndex1D;
    CProxy_Prefix(void) {
    }
    CProxy_Prefix(const ArrayElement *e) : CProxy_ArrayElement(e){
    }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxy_ArrayElement::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxy_ArrayElement::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxy_ArrayElement::pup(p);
    }

    int ckIsDelegated(void) const
    { return CProxy_ArrayElement::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxy_ArrayElement::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxy_ArrayElement::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxy_ArrayElement::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxy_ArrayElement::ckCheck(); }
    inline operator CkArrayID () const
    { return ckGetArrayID(); }
    inline CkArrayID ckGetArrayID(void) const
    { return CProxy_ArrayElement::ckGetArrayID(); }
    inline CkArray *ckLocalBranch(void) const
    { return CProxy_ArrayElement::ckLocalBranch(); }
    inline CkLocMgr *ckLocMgr(void) const
    { return CProxy_ArrayElement::ckLocMgr(); }

    inline static CkArrayID ckCreateEmptyArray(CkArrayOptions opts = CkArrayOptions())
    { return CProxy_ArrayElement::ckCreateEmptyArray(opts); }
    inline static void ckCreateEmptyArrayAsync(CkCallback cb, CkArrayOptions opts = CkArrayOptions())
    { CProxy_ArrayElement::ckCreateEmptyArrayAsync(cb, opts); }
    inline static CkArrayID ckCreateArray(CkArrayMessage *m,int ctor,const CkArrayOptions &opts)
    { return CProxy_ArrayElement::ckCreateArray(m,ctor,opts); }
    inline void ckInsertIdx(CkArrayMessage *m,int ctor,int onPe,const CkArrayIndex &idx)
    { CProxy_ArrayElement::ckInsertIdx(m,ctor,onPe,idx); }
    inline void doneInserting(void)
    { CProxy_ArrayElement::doneInserting(); }

    inline void ckBroadcast(CkArrayMessage *m, int ep, int opts=0) const
    { CProxy_ArrayElement::ckBroadcast(m,ep,opts); }
    inline void setReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxy_ArrayElement::setReductionClient(fn,param); }
    inline void ckSetReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxy_ArrayElement::ckSetReductionClient(fn,param); }
    inline void ckSetReductionClient(CkCallback *cb) const
    { CProxy_ArrayElement::ckSetReductionClient(cb); }

    // Empty array construction
    static CkArrayID ckNew(CkArrayOptions opts = CkArrayOptions()) { return ckCreateEmptyArray(opts); }
    static void      ckNew(CkCallback cb, CkArrayOptions opts = CkArrayOptions()) { ckCreateEmptyArrayAsync(cb, opts); }

    // Generalized array indexing:
    CProxyElement_Prefix operator [] (const CkArrayIndex1D &idx) const
    { return CProxyElement_Prefix(ckGetArrayID(), idx, CK_DELCTOR_CALL); }
    CProxyElement_Prefix operator() (const CkArrayIndex1D &idx) const
    { return CProxyElement_Prefix(ckGetArrayID(), idx, CK_DELCTOR_CALL); }
    CProxyElement_Prefix operator [] (int idx) const 
        {return CProxyElement_Prefix(ckGetArrayID(), CkArrayIndex1D(idx), CK_DELCTOR_CALL);}
    CProxyElement_Prefix operator () (int idx) const 
        {return CProxyElement_Prefix(ckGetArrayID(), CkArrayIndex1D(idx), CK_DELCTOR_CALL);}
    CProxy_Prefix(const CkArrayID &aid,CK_DELCTOR_PARAM) 
        :CProxy_ArrayElement(aid,CK_DELCTOR_ARGS) {}
    CProxy_Prefix(const CkArrayID &aid) 
        :CProxy_ArrayElement(aid) {}
/* DECLS: Prefix(const std::vector<int> &impl_noname_0);
 */
    
    static CkArrayID ckNew(const std::vector<int> &impl_noname_0, const CkArrayOptions &opts = CkArrayOptions(), const CkEntryOptions *impl_e_opts=NULL);
    static void      ckNew(const std::vector<int> &impl_noname_0, const CkArrayOptions &opts, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts=NULL);
    static CkArrayID ckNew(const std::vector<int> &impl_noname_0, const int s1, const CkEntryOptions *impl_e_opts=NULL);
    static void ckNew(const std::vector<int> &impl_noname_0, const int s1, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void phase(int phase);
 */
    
    void phase(int phase, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void passValue(int phase, int value);
 */
    
    void passValue(int phase, int value, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: Prefix(CkMigrateMessage* impl_msg);
 */

};
/* ---------------- section proxy -------------- */
 class CProxySection_Prefix : public CProxySection_ArrayElement{
  public:
    typedef Prefix local_t;
    typedef CkIndex_Prefix index_t;
    typedef CProxy_Prefix proxy_t;
    typedef CProxyElement_Prefix element_t;
    typedef CProxySection_Prefix section_t;

    using array_index_t = CkArrayIndex1D;
    CProxySection_Prefix(void) {
    }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxySection_ArrayElement::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxySection_ArrayElement::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxySection_ArrayElement::pup(p);
    }

    int ckIsDelegated(void) const
    { return CProxySection_ArrayElement::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxySection_ArrayElement::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxySection_ArrayElement::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxySection_ArrayElement::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxySection_ArrayElement::ckCheck(); }
    inline operator CkArrayID () const
    { return ckGetArrayID(); }
    inline CkArrayID ckGetArrayID(void) const
    { return CProxySection_ArrayElement::ckGetArrayID(); }
    inline CkArray *ckLocalBranch(void) const
    { return CProxySection_ArrayElement::ckLocalBranch(); }
    inline CkLocMgr *ckLocMgr(void) const
    { return CProxySection_ArrayElement::ckLocMgr(); }

    inline static CkArrayID ckCreateEmptyArray(CkArrayOptions opts = CkArrayOptions())
    { return CProxySection_ArrayElement::ckCreateEmptyArray(opts); }
    inline static void ckCreateEmptyArrayAsync(CkCallback cb, CkArrayOptions opts = CkArrayOptions())
    { CProxySection_ArrayElement::ckCreateEmptyArrayAsync(cb, opts); }
    inline static CkArrayID ckCreateArray(CkArrayMessage *m,int ctor,const CkArrayOptions &opts)
    { return CProxySection_ArrayElement::ckCreateArray(m,ctor,opts); }
    inline void ckInsertIdx(CkArrayMessage *m,int ctor,int onPe,const CkArrayIndex &idx)
    { CProxySection_ArrayElement::ckInsertIdx(m,ctor,onPe,idx); }
    inline void doneInserting(void)
    { CProxySection_ArrayElement::doneInserting(); }

    inline void ckBroadcast(CkArrayMessage *m, int ep, int opts=0) const
    { CProxySection_ArrayElement::ckBroadcast(m,ep,opts); }
    inline void setReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxySection_ArrayElement::setReductionClient(fn,param); }
    inline void ckSetReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxySection_ArrayElement::ckSetReductionClient(fn,param); }
    inline void ckSetReductionClient(CkCallback *cb) const
    { CProxySection_ArrayElement::ckSetReductionClient(cb); }

    inline void ckSend(CkArrayMessage *m, int ep, int opts = 0)
    { CProxySection_ArrayElement::ckSend(m,ep,opts); }
    inline CkSectionInfo &ckGetSectionInfo()
    { return CProxySection_ArrayElement::ckGetSectionInfo(); }
    inline CkSectionID *ckGetSectionIDs()
    { return CProxySection_ArrayElement::ckGetSectionIDs(); }
    inline CkSectionID &ckGetSectionID()
    { return CProxySection_ArrayElement::ckGetSectionID(); }
    inline CkSectionID &ckGetSectionID(int i)
    { return CProxySection_ArrayElement::ckGetSectionID(i); }
    inline CkArrayID ckGetArrayIDn(int i) const
    { return CProxySection_ArrayElement::ckGetArrayIDn(i); } 
    inline CkArrayIndex *ckGetArrayElements() const
    { return CProxySection_ArrayElement::ckGetArrayElements(); }
    inline CkArrayIndex *ckGetArrayElements(int i) const
    { return CProxySection_ArrayElement::ckGetArrayElements(i); }
    inline int ckGetNumElements() const
    { return CProxySection_ArrayElement::ckGetNumElements(); } 
    inline int ckGetNumElements(int i) const
    { return CProxySection_ArrayElement::ckGetNumElements(i); }    // Generalized array indexing:
    CProxyElement_Prefix operator [] (const CkArrayIndex1D &idx) const
        {return CProxyElement_Prefix(ckGetArrayID(), idx, CK_DELCTOR_CALL);}
    CProxyElement_Prefix operator() (const CkArrayIndex1D &idx) const
        {return CProxyElement_Prefix(ckGetArrayID(), idx, CK_DELCTOR_CALL);}
    CProxyElement_Prefix operator [] (int idx) const 
        {return CProxyElement_Prefix(ckGetArrayID(), *(CkArrayIndex1D*)&ckGetArrayElements()[idx], CK_DELCTOR_CALL);}
    CProxyElement_Prefix operator () (int idx) const 
        {return CProxyElement_Prefix(ckGetArrayID(), *(CkArrayIndex1D*)&ckGetArrayElements()[idx], CK_DELCTOR_CALL);}
    static CkSectionID ckNew(const CkArrayID &aid, CkArrayIndex1D *elems, int nElems, int factor=USE_DEFAULT_BRANCH_FACTOR) {
      return CkSectionID(aid, elems, nElems, factor);
    } 
    static CkSectionID ckNew(const CkArrayID &aid, const std::vector<CkArrayIndex1D> &elems, int factor=USE_DEFAULT_BRANCH_FACTOR) {
      return CkSectionID(aid, elems, factor);
    } 
    static CkSectionID ckNew(const CkArrayID &aid, int l, int u, int s, int factor=USE_DEFAULT_BRANCH_FACTOR) {
      std::vector<CkArrayIndex1D> al;
      for (int i=l; i<=u; i+=s) al.emplace_back(i);
      return CkSectionID(aid, al, factor);
    } 
    CProxySection_Prefix(const CkArrayID &aid, CkArrayIndex *elems, int nElems, CK_DELCTOR_PARAM) 
        :CProxySection_ArrayElement(aid,elems,nElems,CK_DELCTOR_ARGS) {}
    CProxySection_Prefix(const CkArrayID &aid, const std::vector<CkArrayIndex> &elems, CK_DELCTOR_PARAM) 
        :CProxySection_ArrayElement(aid,elems,CK_DELCTOR_ARGS) {}
    CProxySection_Prefix(const CkArrayID &aid, CkArrayIndex *elems, int nElems, int factor=USE_DEFAULT_BRANCH_FACTOR) 
        :CProxySection_ArrayElement(aid,elems,nElems, factor) {}
    CProxySection_Prefix(const CkArrayID &aid, const std::vector<CkArrayIndex> &elems, int factor=USE_DEFAULT_BRANCH_FACTOR) 
        :CProxySection_ArrayElement(aid,elems, factor) { ckAutoDelegate(); }
    CProxySection_Prefix(const CkSectionID &sid)  
        :CProxySection_ArrayElement(sid) { ckAutoDelegate(); }
    CProxySection_Prefix(int n, const CkArrayID *aid, CkArrayIndex const * const *elems, const int *nElems, CK_DELCTOR_PARAM) 
        :CProxySection_ArrayElement(n,aid,elems,nElems,CK_DELCTOR_ARGS) {}
    CProxySection_Prefix(const std::vector<CkArrayID> &aid, const std::vector<std::vector<CkArrayIndex> > &elems, CK_DELCTOR_PARAM) 
        :CProxySection_ArrayElement(aid,elems,CK_DELCTOR_ARGS) {}
    CProxySection_Prefix(int n, const CkArrayID *aid, CkArrayIndex const * const *elems, const int *nElems) 
        :CProxySection_ArrayElement(n,aid,elems,nElems) { ckAutoDelegate(); }
    CProxySection_Prefix(const std::vector<CkArrayID> &aid, const std::vector<std::vector<CkArrayIndex> > &elems) 
        :CProxySection_ArrayElement(aid,elems) { ckAutoDelegate(); }
    CProxySection_Prefix(int n, const CkArrayID *aid, CkArrayIndex const * const *elems, const int *nElems, int factor) 
        :CProxySection_ArrayElement(n,aid,elems,nElems, factor) { ckAutoDelegate(); }
    CProxySection_Prefix(const std::vector<CkArrayID> &aid, const std::vector<std::vector<CkArrayIndex> > &elems, int factor) 
        :CProxySection_ArrayElement(aid,elems, factor) { ckAutoDelegate(); }
    static CkSectionID ckNew(const CkArrayID &aid, CkArrayIndex *elems, int nElems) {
      return CkSectionID(aid, elems, nElems);
    } 
    static CkSectionID ckNew(const CkArrayID &aid, const std::vector<CkArrayIndex> &elems) {
       return CkSectionID(aid, elems);
    } 
    static CkSectionID ckNew(const CkArrayID &aid, CkArrayIndex *elems, int nElems, int factor) {
      return CkSectionID(aid, elems, nElems, factor);
    } 
    static CkSectionID ckNew(const CkArrayID &aid, const std::vector<CkArrayIndex> &elems, int factor) {
      return CkSectionID(aid, elems, factor);
    } 
    void ckAutoDelegate(int opts=1) {
      if(ckIsDelegated()) return;
      CProxySection_ArrayElement::ckAutoDelegate(opts);
    } 
    void setReductionClient(CkCallback *cb) {
      CProxySection_ArrayElement::setReductionClient(cb);
    } 
    void resetSection() {
      CProxySection_ArrayElement::resetSection();
    } 
    static void contribute(CkSectionInfo &sid, int userData=-1, int fragSize=-1);
    static void contribute(int dataSize,void *data,CkReduction::reducerType type, CkSectionInfo &sid, int userData=-1, int fragSize=-1);
    template <typename T>
    static void contribute(std::vector<T> &data, CkReduction::reducerType type, CkSectionInfo &sid, int userData=-1, int fragSize=-1);
    static void contribute(CkSectionInfo &sid, const CkCallback &cb, int userData=-1, int fragSize=-1);
    static void contribute(int dataSize,void *data,CkReduction::reducerType type, CkSectionInfo &sid, const CkCallback &cb, int userData=-1, int fragSize=-1);
    template <typename T>
    static void contribute(std::vector<T> &data, CkReduction::reducerType type, CkSectionInfo &sid, const CkCallback &cb, int userData=-1, int fragSize=-1);
/* DECLS: Prefix(const std::vector<int> &impl_noname_0);
 */
    

/* DECLS: void phase(int phase);
 */
    
    void phase(int phase, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void passValue(int phase, int value);
 */
    
    void passValue(int phase, int value, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: Prefix(CkMigrateMessage* impl_msg);
 */

};
#define Prefix_SDAG_CODE 
typedef CBaseT1<ArrayElementT<CkIndex1D>, CProxy_Prefix>CBase_Prefix;




/* ---------------- method closures -------------- */
class Closure_Main {
  public:


    struct done_2_closure;

};

/* ---------------- method closures -------------- */
class Closure_Prefix {
  public:


    struct phase_2_closure;


    struct passValue_3_closure;


};

extern void _registerprefix(void);
extern "C" void CkRegisterMainModule(void);
#endif