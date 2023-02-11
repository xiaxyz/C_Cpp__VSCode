#include <cstdio>
#define CFileIn(FilePath) FilePath"/in.txt"
#define CFileOut(FilePath) FilePath"/out.txt"
#define CFIn(FilePath) freopen(CFileIn(FilePath), "rt", stdin);
#define CFOut(FilePath) freopen(CFileOut(FilePath), "wt", stdout);
#define CFIO(FilePath) CFIn(FilePath) CFOut(FilePath)