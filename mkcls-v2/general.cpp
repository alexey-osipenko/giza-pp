/*

Copyright (C) 1997,1998,1999,2000,2001  Franz Josef Och

mkcls - a program for making word classes .

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, 
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, 
USA.

*/





#include <stdlib.h>
#include <stdio.h>


extern "C" {
#include <sys/time.h>
#include <sys/resource.h>
  
  
}

#include "general.h"

extern "C" {
#ifndef __linux__
int getrusage(int who, struct rusage *rusage);
#endif
};
int verboseMode=0;

#ifdef aNeXT
#define NO_TEMPLATES
#endif


void myerror(int line,const char *file,const char *expression)
{
  cerr << "(general.h):Assertion failed: '" << expression <<  "' ::: b " 
    << file << ":" << line << endl;
}


void imyerror(int line,const char *file,const char *expression)
{
  cerr << "Error: '" << expression <<  "' ::: in Source " << file 
    << ":" << line << endl;
  #ifndef DEBUG
  
  #endif
}



void zufallSeed(int z)
{
#ifdef NeXT
  srandom(z);
#elif defined(WIN32)
  srand(z);
#else
  srand48(z);
#endif
}



double zufall01()
{
#ifdef NeXT
  return (double)(random()%65536)/65536.0;
#elif defined(WIN32)
  return (double)rand() / RAND_MAX;
#else
  return drand48();
#endif
}



double zufall(double min,double max)
{
  double z=zufall01()*(max-min)+min;
  assert(z>=min&&z<max);
  return z;
}



int randomInt(int exclusive)
{
  int i=(int)zufall(0,exclusive);
  assert(i>=0);
  assert(i<exclusive);
  return i;
}

#ifdef WIN32

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

double clockSec()
{
  FILETIME creation, exit, kernel, user;
  GetProcessTimes(GetCurrentProcess(), &creation, &exit, &kernel, &user);
  LONGLONG time = (LONGLONG(user.dwHighDateTime) << 32) + user.dwLowDateTime;
  return time / 10000000.0;
}

#else // !WIN32

double clockSec()
{
#ifdef linux
  enum __rusage_who who=RUSAGE_SELF;
#else
  int who=RUSAGE_SELF;
#endif
  struct rusage rusage;
  getrusage(who, &rusage);
  return rusage.ru_utime.tv_sec+rusage.ru_utime.tv_usec/1000000.0;
}

#endif // WIN32 / !WIN32