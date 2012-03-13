// Coded by Chun Ming Chin
// Implement the CountMin Sketch
// Find top 1000 words

#include "sketch.h"
#include <string.h>
#include "limits.h"
#include <vector>
#include <iostream>
#include <fstream>



//#include "MurmurHash2_64.cpp"

using namespace std;

int main() {


   FILE *fpa;
   fpa = fopen("enwikiaa", "r"); // Open file for read
   if (NULL == fpa) printf("ERROR opening file \n");

   FILE *fpb;
   fpb = fopen("enwikiab", "r"); // Open file for read
   if (NULL == fpb) printf("ERROR opening file \n");

   FILE *fpc;
   fpc = fopen("enwikiac", "r"); // Open file for read
   if (NULL == fpc) printf("ERROR opening file \n");

   FILE *fpd;
   fpd = fopen("enwikiad", "r"); // Open file for read
   if (NULL == fpd) printf("ERROR opening file \n");

   FILE *fpe;
   fpe = fopen("enwikiae", "r"); // Open file for read
   if (NULL == fpe) printf("ERROR opening file \n");

   FILE *fpf;
   fpf = fopen("enwikiaf", "r"); // Open file for read
   if (NULL == fpf) printf("ERROR opening file \n");

   FILE *fpg;
   fpg = fopen("enwikiag", "r"); // Open file for read
   if (NULL == fpg) printf("ERROR opening file \n");

   FILE *fph;
   fph = fopen("enwikiah", "r"); // Open file for read
   if (NULL == fph) printf("ERROR opening file \n");

   FILE *fpi;
   fpi = fopen("enwikiai", "r"); // Open file for read
   if (NULL == fpi) printf("ERROR opening file \n");

   int errFlag = 0;

   // Declare map for Space Saving
   std::map <string, unsigned int> labelCount; // Seed a common std map

   errFlag = analyze_file(fpa, labelCount);
   errFlag = analyze_file(fpb, labelCount);
   errFlag = analyze_file(fpc, labelCount);
   errFlag = analyze_file(fpd, labelCount);
   errFlag = analyze_file(fpe, labelCount);
   errFlag = analyze_file(fpf, labelCount);
   errFlag = analyze_file(fpg, labelCount);
   errFlag = analyze_file(fph, labelCount);
   errFlag = analyze_file(fpi, labelCount);

   if (errFlag == -1) {
      printf("ERROR in analyzing file \n");
   }   

   fclose(fpa);
   fclose(fpb);  
   fclose(fpc);
   fclose(fpd);
   fclose(fpe);
   fclose(fpf);
   fclose(fpg);
   fclose(fph);
   fclose(fpi);
}

int analyze_file(FILE* fp, std::map <string, unsigned int> &labelCount) {

   char wordc[10000]; 
   char pound = '#';
   char star = '*';
   char ad = '@';
   char accent = '^';
   char dollar = '$';
   char ampersand = '&';
   char percent = '%'; 
   char dot = '.';
   char comma = ',';
   char openBrac = '(';
   char closeBrac = ')';
   char openCurly = '{';
   char closeCurly = '}';
   char openSquare = '[';
   char closeSquare = ']';
   char forwardSlash = '\\';
   char backwardSlash = '/';
   char minus = '-';
   char plus = '+';
   char semiColon = ';';
   char colon = ':';
   char singleQuote = '\'';
   char equal = '=';
   char doubleQuote = '\"';
   char pipe = '|';
   char underScore = '_';
   char one = '1';
   char two = '2';
   char three = '3';
   char four ='4';
   char five = '5';
   char six = '6';
   char seven = '7';
   char eight = '8';
   char nine = '9';
   char zero = '0';
   int errFlag;

   unsigned int index = 0;
   vector<int> wordIdx;

   while(!feof(fp)) {
      fscanf(fp, "%s", wordc); // Remove .,();:""'' multiple=

      unsigned int frontIdx = 0;
      while (frontIdx< strlen(wordc)) { // Find indices of sub words in whole word

	 // Check position of first starting char
         if (	0==strncmp( &wordc[frontIdx], &dot, 1)  ||
		0==strncmp( &wordc[frontIdx], &comma, 1) || 
		0==strncmp( &wordc[frontIdx], &openBrac, 1) ||
		0==strncmp( &wordc[frontIdx], &closeBrac, 1) ||
		0==strncmp( &wordc[frontIdx], &semiColon, 1) ||
		0==strncmp( &wordc[frontIdx], &colon, 1) ||
		0==strncmp( &wordc[frontIdx], &singleQuote, 1) ||
		0==strncmp( &wordc[frontIdx], &equal, 1) ||
		0==strncmp( &wordc[frontIdx], &openCurly, 1) ||
		0==strncmp( &wordc[frontIdx], &closeCurly, 1) ||
		0==strncmp( &wordc[frontIdx], &openSquare, 1) ||
		0==strncmp( &wordc[frontIdx], &closeSquare, 1) ||
		0==strncmp( &wordc[frontIdx], &forwardSlash, 1) ||
		0==strncmp( &wordc[frontIdx], &backwardSlash, 1) ||
		0==strncmp( &wordc[frontIdx], &plus, 1) ||
		0==strncmp( &wordc[frontIdx], &pipe, 1) ||
		0==strncmp( &wordc[frontIdx], &minus, 1) ||
		0==strncmp( &wordc[frontIdx], &underScore, 1) ||
		0==strncmp( &wordc[frontIdx], &one, 1) ||
		0==strncmp( &wordc[frontIdx], &two, 1) ||
		0==strncmp( &wordc[frontIdx], &three, 1) ||
		0==strncmp( &wordc[frontIdx], &four, 1) ||
		0==strncmp( &wordc[frontIdx], &five, 1) ||
		0==strncmp( &wordc[frontIdx], &six, 1) ||
		0==strncmp( &wordc[frontIdx], &seven, 1) ||
		0==strncmp( &wordc[frontIdx], &eight, 1) ||
		0==strncmp( &wordc[frontIdx], &nine, 1) ||
		0==strncmp( &wordc[frontIdx], &zero, 1) ||
		0==strncmp( &wordc[frontIdx], &dollar, 1) ||
		0==strncmp( &wordc[frontIdx], &ampersand, 1) ||
		0==strncmp( &wordc[frontIdx], &percent, 1) ||
		0==strncmp( &wordc[frontIdx], &accent, 1) ||
		0==strncmp( &wordc[frontIdx], &ad, 1) ||
		0==strncmp( &wordc[frontIdx], &pound, 1) ||
		0==strncmp( &wordc[frontIdx], &star, 1) ||
		0==strncmp( &wordc[frontIdx], &doubleQuote, 1) ) {
             
	     frontIdx++;
	  }
	  else {
	     wordIdx.push_back(frontIdx);
	     frontIdx++;
	  }
      }

      // 
      // Extract clean word
      //
      unsigned int vIdx = 0; 
      int startIdx;
      int endIdx;
      int wordLen; // Length of clean word
      char* cleanWord;
 
      while (vIdx < wordIdx.size()) {
         startIdx = wordIdx[vIdx];
	 vIdx++;
	 while ( vIdx<wordIdx.size() && wordIdx[vIdx]==wordIdx[vIdx-1] +1 ) {
	    vIdx++;
	 }
	 endIdx = wordIdx[vIdx-1];

	 wordLen = endIdx - startIdx + 1;
         cleanWord = new char [wordLen+1];
         strncpy ( cleanWord, &wordc[startIdx], wordLen);
         cleanWord[wordLen]='\0';
         string word = string(cleanWord);

         // 
         //Use Space Saving
         //
         errFlag = space_saving_insert(&labelCount, &word, 2000);
         if (-1 == errFlag) {
            printf("Space saving insert ERROR \n");
            return -1;
         }

         delete [] cleanWord;
      }

      wordIdx.clear(); // Clear all elements in vector



 

 
      index++;
      if((index%10000) == 0 ) { // Save frequency 
         ofstream fResult("wiki_result"); // Open file for read
         if (NULL == fResult) printf("ERROR opening file \n");
         for (std::map<string, unsigned int>::iterator it = labelCount.begin(); it != labelCount.end(); ++it) { 
	    fResult << it->first << " " << it->second << "\n";
         }
         fResult.close();
      }
   }
   printf("Completed \n");
   return 0;
}


// Implement hash function from the General Hash Function Library
// Returns an unsigned int value
unsigned int hash_function(int i, const std::string keyPtr) {
   switch (i) {
      case 0:
         return RSHash(keyPtr);
      case 1:
	 return JSHash(keyPtr);
      case 2:
         return PJWHash(keyPtr);
      case 3:
        return  ELFHash(keyPtr);
      case 4:
         return BKDRHash(keyPtr);
      case 5:
         return SDBMHash(keyPtr);
      case 6:
         return DJBHash(keyPtr);
      case 7:
         return DEKHash(keyPtr);
      case 8:
         return BPHash(keyPtr);
      case 9:
         return FNVHash(keyPtr);
      case 10:
         return APHash(keyPtr);
   }

   return -1; // If no case is called, then throw ERROR
}




// 5.3.1 Implement CountMin Sketch
// d : No. of hash functions
// m : No. of bins per hash 
int count_min_insert(unsigned int** hashMatrix, std::string* word, unsigned int d, unsigned int m) {

   if (NULL == word) return -1; // string is empty

   unsigned int idx;
   for (unsigned int i=0; i<d; ++i) { // From 0 to the dth hash function
      idx = hash_function(i, *word);
      hashMatrix[i][idx%m]++; // Mod by no. of bins
      //printf("Count min inserted at bin %u for hash %d, value is %u \n", idx%m, i, hashMatrix[i][idx%m] );
   }
   
   return 0;
}

unsigned int count_min_query(unsigned int** hashMatrix, std::string* word, unsigned int d, unsigned int m) {

   if (NULL == word) return -1; // string is empty

   unsigned int idx;
   unsigned int count;
   unsigned int countMin = UINT_MAX;
   for (unsigned int i=0; i<d; ++i) { // From 0 to the dth hash function
      idx = hash_function(i, *word);
      count = hashMatrix[i][idx%m]; // Mod by no. of bins
      //printf("Count at bin %u for hash %d, value is %u \n", idx%m, i, hashMatrix[i][idx%m] );
      if (count<countMin) {
         countMin = count;
      }
   }
   
   return countMin;
}

// 5.3.2 Implement improved CountMin Sketch for insert only operations
// Only update the mth element in the dth hash function with the min value
int improved_count_min_insert(unsigned int** hashMatrix, std::string* word, unsigned int d, unsigned int m) {

   if (NULL == word) return -1; // string is empty

   unsigned int idx;
   unsigned int count;
   unsigned int minCount = UINT_MAX;
   unsigned int minIdx, minD;
   for (unsigned int i=0; i<d; ++i) { // From 0 to the dth hash function
      idx = hash_function(i, *word);
      count = hashMatrix[i][idx%m];
      if (count < minCount) {
         minCount = count;
	 minD = i; // Which hash function
	 minIdx = idx; // Which index at the particular hash func
      }
   }

   hashMatrix[minD][minIdx]++; // Increment the smallest count only
   return 0;

}

// 5.3.3 Implement SpaceSaving Sketch
// Use BiMap
int space_saving_insert(std::map<string, unsigned int>* labelCount, std::string* label, unsigned int listSize) {


   std::map<string, unsigned int>::iterator fItr;

   //printf("Check 1 \n");

   fItr = (*labelCount).find(*label);

   //printf("Check 2 \n");

   if(fItr == (*labelCount).end()) { // label is not in the list

   //printf ("Check 3 \n");

   //printf("Label is not in list \n");
      if ((*labelCount).size()>=listSize) { // Check if bin size has reached max 

           //printf("The current size is %u \n", (unsigned int) (*labelCount).size());
       
	 unsigned int minCount = UINT_MAX;
	 string minLabel;
         for (std::map<string, unsigned int>::iterator it = (*labelCount).begin(); it != (*labelCount).end(); ++it) { // Find label with smallest count
	    if (it->second < minCount) {
	       minCount = it->second;
	       minLabel = it->first; 
	    }
         }

         //std::cout << "Deleted label is: " << minLabel << "\n";
         (*labelCount).erase(minLabel); // Set label to new
	 (*labelCount)[*label] = minCount + 1; // Update count
         //printf("New count is %u \n", (*labelCount)[*label]);
         //std::cout << "Label is: " << *label << "\n";

      }

      else { // Just add on to the list

           //printf("The open size is %u \n", (unsigned int)(*labelCount).size());
 
	 (*labelCount)[*label] = 1; // Update count
      }
   }
   else { 
      fItr->second++; // Label is in the list
      //printf("Space saving value is %u \n", fItr->second);
   }

  return 0; // std::map <string, unsigned int> labelCount;
}


/*


   int d = 10; // No. of hash functions
   int m = 100000; // Max no. of bins
   std::string word;


   // Allocate memory for Count Min
   unsigned int** hashTable = new unsigned int* [d];
   if (NULL==hashTable) {
      printf("Mem allocation ERROR \n");
      return -1;
   }

   for (int i=0; i<d; i++) {
      hashTable[i] = new unsigned int [m];
      memset(hashTable[i], NULL, m*sizeof(unsigned int)); // Ini. elements to 0

      if (NULL==hashTable[i]) {
         printf("Mem allocation ERROR \n");
	 return -1;
      }
   }


      //
      // Insert word into Count Min Hash Table
      //
      errFlag = count_min_insert(hashTable, &word, d, m);
      if (-1 == errFlag) {
         printf("Count min insert ERROR \n");
         return -1;
      }

      //
      // Query Count Min for result
      //
      //unsigned int count = count_min_query(hashTable, &word, d, m);
      //printf("Count is %u \n", count);

   // Deallocate memory 
   for (int i=0; i<d; i++) {
      delete [] hashTable[i];
   }
   delete [] hashTable;
*/



