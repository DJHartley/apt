// -*- mode: cpp; mode: fold -*-
// Description								/*{{{*/
// $Id: debversion.h,v 1.3 2001/05/03 05:25:04 jgg Exp $
/* ######################################################################

   Debian Version - Versioning system for Debian

   This implements the standard Debian versioning system.
   
   ##################################################################### */
									/*}}}*/
#ifndef PKGLIB_DEBVERSION_H
#define PKGLIB_DEBVERSION_H

#include <apt-pkg/version.h>

#include <string>

class debVersioningSystem : public pkgVersioningSystem
{
   public:

   static int CmpFragment(const char *A, const char *AEnd, const char *B,
			  const char *BEnd) APT_PURE;

   // Compare versions..
   virtual int DoCmpVersion(const char *A,const char *Aend,
			  const char *B,const char *Bend) APT_PURE;
   virtual bool CheckDep(const char *PkgVer,int Op,const char *DepVer) APT_PURE;
   virtual APT_PURE int DoCmpReleaseVer(const char *A,const char *Aend,
			     const char *B,const char *Bend)
   {
      return DoCmpVersion(A,Aend,B,Bend);
   }
   virtual std::string UpstreamVersion(const char *A);

   debVersioningSystem();
};

extern debVersioningSystem debVS;

#endif
