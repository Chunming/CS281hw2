// Coded by Chun Ming Chin
// Implement the CountMin Sketch
// Find top 1000 words

#include "space_saving.h"
#include <string.h>
#include "limits.h"
#include <vector>
#include <iostream>
#include <fstream>

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
   if (errFlag == -1) {printf("ERROR in analyzing file \n");}     
    
   errFlag = analyze_file(fpb, labelCount);
   if (errFlag == -1) {printf("ERROR in analyzing file \n");}   
   
   errFlag = analyze_file(fpc, labelCount);
   if (errFlag == -1) {printf("ERROR in analyzing file \n");}   
   
   errFlag = analyze_file(fpd, labelCount);
   if (errFlag == -1) {printf("ERROR in analyzing file \n");}   
   
   errFlag = analyze_file(fpe, labelCount);
   if (errFlag == -1) {printf("ERROR in analyzing file \n");}   
   
   errFlag = analyze_file(fpf, labelCount);
   if (errFlag == -1) {printf("ERROR in analyzing file \n");}   
   
   errFlag = analyze_file(fpg, labelCount);
   if (errFlag == -1) {printf("ERROR in analyzing file \n");}   
   
   errFlag = analyze_file(fph, labelCount);
   if (errFlag == -1) {printf("ERROR in analyzing file \n");}   
   
   errFlag = analyze_file(fpi, labelCount);
   if (errFlag == -1) {printf("ERROR in analyzing file \n");}   

   ofstream fResult("space_saving_result.txt"); // Open file for read
   if (NULL == fResult) printf("ERROR opening file \n");
   for (std::map<string, unsigned int>::iterator it = labelCount.begin(); it != labelCount.end(); ++it) { 
      fResult << it->first << " " << it->second << "\n";
   }
   fResult.close();

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
   char leftArrow = '<';
   char rightArrow = '>';
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
		0==strncmp( &wordc[frontIdx], &leftArrow, 1) ||
		0==strncmp( &wordc[frontIdx], &rightArrow, 1) ||
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

	printf("%s \n", cleanWord);

         // 
         //Use Space Saving
         //
         //std::cout << "Word is " << word << "\n";
         errFlag = space_saving_insert(&labelCount, &word, 2000);
         if (-1 == errFlag) {
            printf("Space saving insert ERROR \n");
            return -1;
         }

         delete [] cleanWord;
      }

      wordIdx.clear(); // Clear all elements in vector

      index++;
   }
   printf("Completed \n");
   return 0;
}

// 5.3.3 Implement SpaceSaving Sketch
// Use BiMap
int space_saving_insert(std::map<string, unsigned int>* labelCount, std::string* label, unsigned int listSize) {

   std::map<string, unsigned int>::iterator fItr;
   fItr = (*labelCount).find(*label);
   if(fItr == (*labelCount).end()) { // label is not in the list
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
         (*labelCount).erase(minLabel);
	 (*labelCount)[*label] = minCount + 1; // Update count
         if (minCount == UINT_MAX) {printf("Warning: Buffer overflow in Map \n");}

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


