/**************************************************************************
***
*** Copyright (c) 2000-2006 Regents of the University of Michigan,
***               Saurabh N. Adya, Hayward Chan, Jarrod A. Roy
***               and Igor L. Markov
***
***  Contact author(s): sadya@umich.edu, imarkov@umich.edu
***  Original Affiliation:   University of Michigan, EECS Dept.
***                          Ann Arbor, MI 48109-2122 USA
***
***  Permission is hereby granted, free of charge, to any person obtaining 
***  a copy of this software and associated documentation files (the
***  "Software"), to deal in the Software without restriction, including
***  without limitation 
***  the rights to use, copy, modify, merge, publish, distribute, sublicense, 
***  and/or sell copies of the Software, and to permit persons to whom the 
***  Software is furnished to do so, subject to the following conditions:
***
***  The above copyright notice and this permission notice shall be included
***  in all copies or substantial portions of the Software.
***
*** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
*** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
*** OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
*** IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
*** CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT
*** OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR
*** THE USE OR OTHER DEALINGS IN THE SOFTWARE.
***
***
***************************************************************************/


#ifndef _PARQUET_H_
#define _PARQUET_H_


#include "FPcommon.h"
#include "Annealer.h"
#include "CommandLine.h"
#include "ClusterDB.h"
#include "SolveMulti.h"
#include "ABKCommon/infolines.h"

// --------------------------------------------------------
class Parquet
{
public:
   Parquet(int argc, char **argv, int verbosity);
   
   int go();
   inline const parquetfp::Command_Line& parameters() const;

   float getBestXSize() const { return bestXSize; }
   float getBestYSize() const { return bestYSize; }
   float getBestArea() const { return bestArea; }
   float getBestWL() const { return bestWL; }
   float getBestWS() const { return bestWS; }
   
protected:
   parquetfp::Command_Line params;

private:
   Parquet();
   Parquet(const Parquet&);
   
   // area and wirelength for the best floorplan encountered
   float bestXSize;
   float bestYSize;
   float bestArea;
   float bestWL;
   float bestWS;
   
   // verbosity == 0 => silence
   // versbosity > 1 => all output
   int verbosity;
};
// --------------------------------------------------------

// ===============
// IMPLEMENTATIONS
// ===============
const parquetfp::Command_Line& Parquet::parameters() const
{   return params; }
// --------------------------------------------------------

#endif
