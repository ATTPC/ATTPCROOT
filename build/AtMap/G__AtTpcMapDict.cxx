//
// File generated by /usr/local/fairsoft/fairsoft_jul14p3-install/bin/rootcint at Fri Feb 13 17:59:03 2015

// Do NOT change. Changes will be lost next time file is generated
//

#define R__DICTIONARY_FILENAME dIhomedIdaqdIfair_install_2015dIATTPCROOT_FebdIbuilddIAtMapdIG__AtTpcMapDict
#include "RConfig.h" //rootcint 4834
#if !defined(R__ACCESS_IN_SYMBOL)
//Break the privacy of classes -- Disabled for the moment
#define private public
#define protected public
#endif

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;
#include "G__AtTpcMapDict.h"

#include "TClass.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"

// Direct notice to TROOT of the dictionary's loading.
namespace {
   static struct DictInit {
      DictInit() {
         ROOT::RegisterModule();
      }
   } __TheDictionaryInitializer;
}

// START OF SHADOWS

namespace ROOT {
   namespace Shadow {
   } // of namespace Shadow
} // of namespace ROOT
// END OF SHADOWS

namespace ROOT {
   void AtTpcMap_ShowMembers(void *obj, TMemberInspector &R__insp);
   static void *new_AtTpcMap(void *p = 0);
   static void *newArray_AtTpcMap(Long_t size, void *p);
   static void delete_AtTpcMap(void *p);
   static void deleteArray_AtTpcMap(void *p);
   static void destruct_AtTpcMap(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::AtTpcMap*)
   {
      ::AtTpcMap *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::AtTpcMap >(0);
      static ::ROOT::TGenericClassInfo 
         instance("AtTpcMap", ::AtTpcMap::Class_Version(), "/home/daq/fair_install_2015/ATTPCROOT_Feb/AtMap/AtTpcMap.h", 15,
                  typeid(::AtTpcMap), DefineBehavior(ptr, ptr),
                  &::AtTpcMap::Dictionary, isa_proxy, 4,
                  sizeof(::AtTpcMap) );
      instance.SetNew(&new_AtTpcMap);
      instance.SetNewArray(&newArray_AtTpcMap);
      instance.SetDelete(&delete_AtTpcMap);
      instance.SetDeleteArray(&deleteArray_AtTpcMap);
      instance.SetDestructor(&destruct_AtTpcMap);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::AtTpcMap*)
   {
      return GenerateInitInstanceLocal((::AtTpcMap*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::AtTpcMap*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
TClass *AtTpcMap::fgIsA = 0;  // static to hold class pointer

//______________________________________________________________________________
const char *AtTpcMap::Class_Name()
{
   return "AtTpcMap";
}

//______________________________________________________________________________
const char *AtTpcMap::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::AtTpcMap*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int AtTpcMap::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::AtTpcMap*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
void AtTpcMap::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::AtTpcMap*)0x0)->GetClass();
}

//______________________________________________________________________________
TClass *AtTpcMap::Class()
{
   if (!fgIsA) fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::AtTpcMap*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
void AtTpcMap::Streamer(TBuffer &R__b)
{
   // Stream an object of class AtTpcMap.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(AtTpcMap::Class(),this);
   } else {
      R__b.WriteClassBuffer(AtTpcMap::Class(),this);
   }
}

//______________________________________________________________________________
void AtTpcMap::ShowMembers(TMemberInspector &R__insp)
{
      // Inspect the data members of an object of class AtTpcMap.
      TClass *R__cl = ::AtTpcMap::IsA();
      if (R__cl || R__insp.IsA()) { }
      TObject::ShowMembers(R__insp);
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_AtTpcMap(void *p) {
      return  p ? new(p) ::AtTpcMap : new ::AtTpcMap;
   }
   static void *newArray_AtTpcMap(Long_t nElements, void *p) {
      return p ? new(p) ::AtTpcMap[nElements] : new ::AtTpcMap[nElements];
   }
   // Wrapper around operator delete
   static void delete_AtTpcMap(void *p) {
      delete ((::AtTpcMap*)p);
   }
   static void deleteArray_AtTpcMap(void *p) {
      delete [] ((::AtTpcMap*)p);
   }
   static void destruct_AtTpcMap(void *p) {
      typedef ::AtTpcMap current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::AtTpcMap

/********************************************************
* /home/daq/fair_install_2015/ATTPCROOT_Feb/build/AtMap/G__AtTpcMapDict.cxx
* CAUTION: DON'T CHANGE THIS FILE. THIS FILE IS AUTOMATICALLY GENERATED
*          FROM HEADER FILES LISTED IN G__setup_cpp_environmentXXX().
*          CHANGE THOSE HEADER FILES AND REGENERATE THIS FILE.
********************************************************/

#ifdef G__MEMTEST
#undef malloc
#undef free
#endif

#if defined(__GNUC__) && __GNUC__ >= 4 && ((__GNUC_MINOR__ == 2 && __GNUC_PATCHLEVEL__ >= 1) || (__GNUC_MINOR__ >= 3))
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif

extern "C" void G__cpp_reset_tagtableG__AtTpcMapDict();

extern "C" void G__set_cpp_environmentG__AtTpcMapDict() {
  G__add_compiledheader("TObject.h");
  G__add_compiledheader("TMemberInspector.h");
  G__add_compiledheader("AtTpcMap.h");
  G__cpp_reset_tagtableG__AtTpcMapDict();
}
#include <new>
extern "C" int G__cpp_dllrevG__AtTpcMapDict() { return(30051515); }

/*********************************************************
* Member function Interface Method
*********************************************************/

/* AtTpcMap */
static int G__G__AtTpcMapDict_168_0_1(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   AtTpcMap* p = NULL;
   char* gvp = (char*) G__getgvp();
   int n = G__getaryconstruct();
   if (n) {
     if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
       p = new AtTpcMap[n];
     } else {
       p = new((void*) gvp) AtTpcMap[n];
     }
   } else {
     if ((gvp == (char*)G__PVOID) || (gvp == 0)) {
       p = new AtTpcMap;
     } else {
       p = new((void*) gvp) AtTpcMap;
     }
   }
   result7->obj.i = (long) p;
   result7->ref = (long) p;
   G__set_tagnum(result7,G__get_linked_tagnum(&G__G__AtTpcMapDictLN_AtTpcMap));
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__G__AtTpcMapDict_168_0_2(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 85, (long) AtTpcMap::Class());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__G__AtTpcMapDict_168_0_3(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 67, (long) AtTpcMap::Class_Name());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__G__AtTpcMapDict_168_0_4(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 115, (long) AtTpcMap::Class_Version());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__G__AtTpcMapDict_168_0_5(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      AtTpcMap::Dictionary();
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__G__AtTpcMapDict_168_0_9(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      ((AtTpcMap*) G__getstructoffset())->StreamerNVirtual(*(TBuffer*) libp->para[0].ref);
      G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__G__AtTpcMapDict_168_0_10(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 67, (long) AtTpcMap::DeclFileName());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__G__AtTpcMapDict_168_0_11(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 105, (long) AtTpcMap::ImplFileLine());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__G__AtTpcMapDict_168_0_12(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 67, (long) AtTpcMap::ImplFileName());
   return(1 || funcname || hash || result7 || libp) ;
}

static int G__G__AtTpcMapDict_168_0_13(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
      G__letint(result7, 105, (long) AtTpcMap::DeclFileLine());
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic copy constructor
static int G__G__AtTpcMapDict_168_0_14(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)

{
   AtTpcMap* p;
   void* tmp = (void*) G__int(libp->para[0]);
   p = new AtTpcMap(*(AtTpcMap*) tmp);
   result7->obj.i = (long) p;
   result7->ref = (long) p;
   G__set_tagnum(result7,G__get_linked_tagnum(&G__G__AtTpcMapDictLN_AtTpcMap));
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic destructor
typedef AtTpcMap G__TAtTpcMap;
static int G__G__AtTpcMapDict_168_0_15(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   char* gvp = (char*) G__getgvp();
   long soff = G__getstructoffset();
   int n = G__getaryconstruct();
   //
   //has_a_delete: 1
   //has_own_delete1arg: 0
   //has_own_delete2arg: 0
   //
   if (!soff) {
     return(1);
   }
   if (n) {
     if (gvp == (char*)G__PVOID) {
       delete[] (AtTpcMap*) soff;
     } else {
       G__setgvp((long) G__PVOID);
       for (int i = n - 1; i >= 0; --i) {
         ((AtTpcMap*) (soff+(sizeof(AtTpcMap)*i)))->~G__TAtTpcMap();
       }
       G__setgvp((long)gvp);
     }
   } else {
     if (gvp == (char*)G__PVOID) {
       delete (AtTpcMap*) soff;
     } else {
       G__setgvp((long) G__PVOID);
       ((AtTpcMap*) (soff))->~G__TAtTpcMap();
       G__setgvp((long)gvp);
     }
   }
   G__setnull(result7);
   return(1 || funcname || hash || result7 || libp) ;
}

// automatic assignment operator
static int G__G__AtTpcMapDict_168_0_16(G__value* result7, G__CONST char* funcname, struct G__param* libp, int hash)
{
   AtTpcMap* dest = (AtTpcMap*) G__getstructoffset();
   *dest = *(AtTpcMap*) libp->para[0].ref;
   const AtTpcMap& obj = *dest;
   result7->ref = (long) (&obj);
   result7->obj.i = (long) (&obj);
   return(1 || funcname || hash || result7 || libp) ;
}


/* Setting up global function */

/*********************************************************
* Member function Stub
*********************************************************/

/* AtTpcMap */

/*********************************************************
* Global function Stub
*********************************************************/

/*********************************************************
* Get size of pointer to member function
*********************************************************/
class G__Sizep2memfuncG__AtTpcMapDict {
 public:
  G__Sizep2memfuncG__AtTpcMapDict(): p(&G__Sizep2memfuncG__AtTpcMapDict::sizep2memfunc) {}
    size_t sizep2memfunc() { return(sizeof(p)); }
  private:
    size_t (G__Sizep2memfuncG__AtTpcMapDict::*p)();
};

size_t G__get_sizep2memfuncG__AtTpcMapDict()
{
  G__Sizep2memfuncG__AtTpcMapDict a;
  G__setsizep2memfunc((int)a.sizep2memfunc());
  return((size_t)a.sizep2memfunc());
}


/*********************************************************
* virtual base class offset calculation interface
*********************************************************/

   /* Setting up class inheritance */

/*********************************************************
* Inheritance information setup/
*********************************************************/
extern "C" void G__cpp_setup_inheritanceG__AtTpcMapDict() {

   /* Setting up class inheritance */
   if(0==G__getnumbaseclass(G__get_linked_tagnum(&G__G__AtTpcMapDictLN_AtTpcMap))) {
     AtTpcMap *G__Lderived;
     G__Lderived=(AtTpcMap*)0x1000;
     {
       TObject *G__Lpbase=(TObject*)G__Lderived;
       G__inheritance_setup(G__get_linked_tagnum(&G__G__AtTpcMapDictLN_AtTpcMap),G__get_linked_tagnum(&G__G__AtTpcMapDictLN_TObject),(long)G__Lpbase-(long)G__Lderived,1,1);
     }
   }
}

/*********************************************************
* typedef information setup/
*********************************************************/
extern "C" void G__cpp_setup_typetableG__AtTpcMapDict() {

   /* Setting up typedef entry */
   G__search_typename2("Version_t",115,-1,0,-1);
   G__setnewtype(-1,"Class version identifier (short)",0);
   G__search_typename2("vector<ROOT::TSchemaHelper>",117,G__get_linked_tagnum(&G__G__AtTpcMapDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<const_iterator>",117,G__get_linked_tagnum(&G__G__AtTpcMapDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__G__AtTpcMapDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<iterator>",117,G__get_linked_tagnum(&G__G__AtTpcMapDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__G__AtTpcMapDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("vector<TVirtualArray*>",117,G__get_linked_tagnum(&G__G__AtTpcMapDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR),0,-1);
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<const_iterator>",117,G__get_linked_tagnum(&G__G__AtTpcMapDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__G__AtTpcMapDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR));
   G__setnewtype(-1,NULL,0);
   G__search_typename2("reverse_iterator<iterator>",117,G__get_linked_tagnum(&G__G__AtTpcMapDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR),0,G__get_linked_tagnum(&G__G__AtTpcMapDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR));
   G__setnewtype(-1,NULL,0);
}

/*********************************************************
* Data Member information setup/
*********************************************************/

   /* Setting up class,struct,union tag member variable */

   /* AtTpcMap */
static void G__setup_memvarAtTpcMap(void) {
   G__tag_memvar_setup(G__get_linked_tagnum(&G__G__AtTpcMapDictLN_AtTpcMap));
   { AtTpcMap *p; p=(AtTpcMap*)0x1000; if (p) { }
   G__memvar_setup((void*)0,85,0,0,G__get_linked_tagnum(&G__G__AtTpcMapDictLN_TClass),-1,-2,4,"fgIsA=",0,(char*)NULL);
   }
   G__tag_memvar_reset();
}

extern "C" void G__cpp_setup_memvarG__AtTpcMapDict() {
}
/***********************************************************
************************************************************
************************************************************
************************************************************
************************************************************
************************************************************
************************************************************
***********************************************************/

/*********************************************************
* Member function information setup for each class
*********************************************************/
static void G__setup_memfuncAtTpcMap(void) {
   /* AtTpcMap */
   G__tag_memfunc_setup(G__get_linked_tagnum(&G__G__AtTpcMapDictLN_AtTpcMap));
   G__memfunc_setup("AtTpcMap",762,G__G__AtTpcMapDict_168_0_1, 105, G__get_linked_tagnum(&G__G__AtTpcMapDictLN_AtTpcMap), -1, 0, 0, 1, 1, 0, "", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("Class",502,G__G__AtTpcMapDict_168_0_2, 85, G__get_linked_tagnum(&G__G__AtTpcMapDictLN_TClass), -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (TClass* (*)())(&AtTpcMap::Class) ), 0);
   G__memfunc_setup("Class_Name",982,G__G__AtTpcMapDict_168_0_3, 67, -1, -1, 0, 0, 3, 1, 1, "", (char*)NULL, (void*) G__func2void( (const char* (*)())(&AtTpcMap::Class_Name) ), 0);
   G__memfunc_setup("Class_Version",1339,G__G__AtTpcMapDict_168_0_4, 115, -1, G__defined_typename("Version_t"), 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (Version_t (*)())(&AtTpcMap::Class_Version) ), 0);
   G__memfunc_setup("Dictionary",1046,G__G__AtTpcMapDict_168_0_5, 121, -1, -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (void (*)())(&AtTpcMap::Dictionary) ), 0);
   G__memfunc_setup("IsA",253,(G__InterfaceMethod) NULL,85, G__get_linked_tagnum(&G__G__AtTpcMapDictLN_TClass), -1, 0, 0, 1, 1, 8, "", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("ShowMembers",1132,(G__InterfaceMethod) NULL,121, -1, -1, 0, 1, 1, 1, 0, "u 'TMemberInspector' - 1 - -", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("Streamer",835,(G__InterfaceMethod) NULL,121, -1, -1, 0, 1, 1, 1, 0, "u 'TBuffer' - 1 - -", (char*)NULL, (void*) NULL, 1);
   G__memfunc_setup("StreamerNVirtual",1656,G__G__AtTpcMapDict_168_0_9, 121, -1, -1, 0, 1, 1, 1, 0, "u 'TBuffer' - 1 - ClassDef_StreamerNVirtual_b", (char*)NULL, (void*) NULL, 0);
   G__memfunc_setup("DeclFileName",1145,G__G__AtTpcMapDict_168_0_10, 67, -1, -1, 0, 0, 3, 1, 1, "", (char*)NULL, (void*) G__func2void( (const char* (*)())(&AtTpcMap::DeclFileName) ), 0);
   G__memfunc_setup("ImplFileLine",1178,G__G__AtTpcMapDict_168_0_11, 105, -1, -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (int (*)())(&AtTpcMap::ImplFileLine) ), 0);
   G__memfunc_setup("ImplFileName",1171,G__G__AtTpcMapDict_168_0_12, 67, -1, -1, 0, 0, 3, 1, 1, "", (char*)NULL, (void*) G__func2void( (const char* (*)())(&AtTpcMap::ImplFileName) ), 0);
   G__memfunc_setup("DeclFileLine",1152,G__G__AtTpcMapDict_168_0_13, 105, -1, -1, 0, 0, 3, 1, 0, "", (char*)NULL, (void*) G__func2void( (int (*)())(&AtTpcMap::DeclFileLine) ), 0);
   // automatic copy constructor
   G__memfunc_setup("AtTpcMap", 762, G__G__AtTpcMapDict_168_0_14, (int) ('i'), G__get_linked_tagnum(&G__G__AtTpcMapDictLN_AtTpcMap), -1, 0, 1, 1, 1, 0, "u 'AtTpcMap' - 11 - -", (char*) NULL, (void*) NULL, 0);
   // automatic destructor
   G__memfunc_setup("~AtTpcMap", 888, G__G__AtTpcMapDict_168_0_15, (int) ('y'), -1, -1, 0, 0, 1, 1, 0, "", (char*) NULL, (void*) NULL, 1);
   // automatic assignment operator
   G__memfunc_setup("operator=", 937, G__G__AtTpcMapDict_168_0_16, (int) ('u'), G__get_linked_tagnum(&G__G__AtTpcMapDictLN_AtTpcMap), -1, 1, 1, 1, 1, 0, "u 'AtTpcMap' - 11 - -", (char*) NULL, (void*) NULL, 0);
   G__tag_memfunc_reset();
}


/*********************************************************
* Member function information setup
*********************************************************/
extern "C" void G__cpp_setup_memfuncG__AtTpcMapDict() {
}

/*********************************************************
* Global variable information setup for each class
*********************************************************/
static void G__cpp_setup_global0() {

   /* Setting up global variables */
   G__resetplocal();

}

static void G__cpp_setup_global1() {

   G__resetglobalenv();
}
extern "C" void G__cpp_setup_globalG__AtTpcMapDict() {
  G__cpp_setup_global0();
  G__cpp_setup_global1();
}

/*********************************************************
* Global function information setup for each class
*********************************************************/
static void G__cpp_setup_func0() {
   G__lastifuncposition();

}

static void G__cpp_setup_func1() {
}

static void G__cpp_setup_func2() {
}

static void G__cpp_setup_func3() {
}

static void G__cpp_setup_func4() {
}

static void G__cpp_setup_func5() {
}

static void G__cpp_setup_func6() {
}

static void G__cpp_setup_func7() {
}

static void G__cpp_setup_func8() {
}

static void G__cpp_setup_func9() {
}

static void G__cpp_setup_func10() {
}

static void G__cpp_setup_func11() {
}

static void G__cpp_setup_func12() {

   G__resetifuncposition();
}

extern "C" void G__cpp_setup_funcG__AtTpcMapDict() {
  G__cpp_setup_func0();
  G__cpp_setup_func1();
  G__cpp_setup_func2();
  G__cpp_setup_func3();
  G__cpp_setup_func4();
  G__cpp_setup_func5();
  G__cpp_setup_func6();
  G__cpp_setup_func7();
  G__cpp_setup_func8();
  G__cpp_setup_func9();
  G__cpp_setup_func10();
  G__cpp_setup_func11();
  G__cpp_setup_func12();
}

/*********************************************************
* Class,struct,union,enum tag information setup
*********************************************************/
/* Setup class/struct taginfo */
G__linked_taginfo G__G__AtTpcMapDictLN_TClass = { "TClass" , 99 , -1 };
G__linked_taginfo G__G__AtTpcMapDictLN_TBuffer = { "TBuffer" , 99 , -1 };
G__linked_taginfo G__G__AtTpcMapDictLN_TMemberInspector = { "TMemberInspector" , 99 , -1 };
G__linked_taginfo G__G__AtTpcMapDictLN_TObject = { "TObject" , 99 , -1 };
G__linked_taginfo G__G__AtTpcMapDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR = { "vector<ROOT::TSchemaHelper,allocator<ROOT::TSchemaHelper> >" , 99 , -1 };
G__linked_taginfo G__G__AtTpcMapDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR = { "reverse_iterator<vector<ROOT::TSchemaHelper,allocator<ROOT::TSchemaHelper> >::iterator>" , 99 , -1 };
G__linked_taginfo G__G__AtTpcMapDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR = { "vector<TVirtualArray*,allocator<TVirtualArray*> >" , 99 , -1 };
G__linked_taginfo G__G__AtTpcMapDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR = { "reverse_iterator<vector<TVirtualArray*,allocator<TVirtualArray*> >::iterator>" , 99 , -1 };
G__linked_taginfo G__G__AtTpcMapDictLN_AtTpcMap = { "AtTpcMap" , 99 , -1 };

/* Reset class/struct taginfo */
extern "C" void G__cpp_reset_tagtableG__AtTpcMapDict() {
  G__G__AtTpcMapDictLN_TClass.tagnum = -1 ;
  G__G__AtTpcMapDictLN_TBuffer.tagnum = -1 ;
  G__G__AtTpcMapDictLN_TMemberInspector.tagnum = -1 ;
  G__G__AtTpcMapDictLN_TObject.tagnum = -1 ;
  G__G__AtTpcMapDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR.tagnum = -1 ;
  G__G__AtTpcMapDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR.tagnum = -1 ;
  G__G__AtTpcMapDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR.tagnum = -1 ;
  G__G__AtTpcMapDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR.tagnum = -1 ;
  G__G__AtTpcMapDictLN_AtTpcMap.tagnum = -1 ;
}


extern "C" void G__cpp_setup_tagtableG__AtTpcMapDict() {

   /* Setting up class,struct,union tag entry */
   G__get_linked_tagnum_fwd(&G__G__AtTpcMapDictLN_TClass);
   G__get_linked_tagnum_fwd(&G__G__AtTpcMapDictLN_TBuffer);
   G__get_linked_tagnum_fwd(&G__G__AtTpcMapDictLN_TMemberInspector);
   G__get_linked_tagnum_fwd(&G__G__AtTpcMapDictLN_TObject);
   G__get_linked_tagnum_fwd(&G__G__AtTpcMapDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR);
   G__get_linked_tagnum_fwd(&G__G__AtTpcMapDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR);
   G__get_linked_tagnum_fwd(&G__G__AtTpcMapDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR);
   G__get_linked_tagnum_fwd(&G__G__AtTpcMapDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR);
   G__tagtable_setup(G__get_linked_tagnum_fwd(&G__G__AtTpcMapDictLN_AtTpcMap),sizeof(AtTpcMap),-1,292096,(char*)NULL,G__setup_memvarAtTpcMap,G__setup_memfuncAtTpcMap);
}
extern "C" void G__cpp_setupG__AtTpcMapDict(void) {
  G__check_setup_version(30051515,"G__cpp_setupG__AtTpcMapDict()");
  G__set_cpp_environmentG__AtTpcMapDict();
  G__cpp_setup_tagtableG__AtTpcMapDict();

  G__cpp_setup_inheritanceG__AtTpcMapDict();

  G__cpp_setup_typetableG__AtTpcMapDict();

  G__cpp_setup_memvarG__AtTpcMapDict();

  G__cpp_setup_memfuncG__AtTpcMapDict();
  G__cpp_setup_globalG__AtTpcMapDict();
  G__cpp_setup_funcG__AtTpcMapDict();

   if(0==G__getsizep2memfunc()) G__get_sizep2memfuncG__AtTpcMapDict();
  return;
}
class G__cpp_setup_initG__AtTpcMapDict {
  public:
    G__cpp_setup_initG__AtTpcMapDict() { G__add_setup_func("G__AtTpcMapDict",(G__incsetup)(&G__cpp_setupG__AtTpcMapDict)); G__call_setup_funcs(); }
   ~G__cpp_setup_initG__AtTpcMapDict() { G__remove_setup_func("G__AtTpcMapDict"); }
};
G__cpp_setup_initG__AtTpcMapDict G__cpp_setup_initializerG__AtTpcMapDict;

