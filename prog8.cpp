/* Program 8 - Katelyn Stamas-Nickandros
 Program will maintain a database on at least 5 objects using a class and 
 an array of objects in that class.
*/
#include <iostream>
#include <fstream>
using namespace std;
class distillerInfo {
 public:
    string name;
    string city;
    string state;
};
class alcoholContent {
 public:
    double proof;
    double percent;
};
class age {
 public:
    string barrel;
    int years;
};
class katesWhiskey {
 public:
    string bottleName;
    distillerInfo distiller;
    string type;
    alcoholContent alcohol;
    age ageInfo;
};
void readdata (katesWhiskey[], int&);
void printall (katesWhiskey[], int);
void sort (katesWhiskey[], int);
void findType (katesWhiskey[], int, string&);
void printone (katesWhiskey);
ifstream infile ("whiskey_list.txt");
ofstream outfile ("kates_whiskey.txt");
int main()
{
    katesWhiskey whiskey[15];
    int n;
    string lookFor;
    
    readdata (whiskey, n);
    outfile << "----- ORIGINAL WHISKEY LIST -----" << endl;
    printall (whiskey, n);
    sort (whiskey, n);
    outfile << "----- WHISKEY LIST SORTED BY PROOF -----" << endl;
    printall (whiskey, n);
    findType (whiskey, n, lookFor);

    infile.close();
    outfile.close();
    return 0;
}

/*
 Input: receives two parameters from the main program, an array of
  objects and n
 Process: will read in data from from a file
 Output: data will be stored and organized in classes and objects
*/
void readdata (katesWhiskey entry[], int &n) {
    infile >> n;
    for (int i = 0; i < n; i++) {
        infile >> entry[i].bottleName;
        infile >> entry[i].distiller.name;
        infile >> entry[i].distiller.city;
        infile >> entry[i].distiller.state;
        infile >> entry[i].type;
        infile >> entry[i].alcohol.proof;
        entry[i].alcohol.percent = entry[i].alcohol.proof / 2;
        infile >> entry[i].ageInfo.barrel;
        infile >> entry[i].ageInfo.years;
    }
    return;
}

/*
 Input: receives two parameters from the main program, an array of
  objects and n
 Process: will print all of the information in the array of objects
 Output: return to main program
*/
void printall (katesWhiskey entry[], int n) {
    for (int i = 0; i < n; i++) {
        outfile << "Bottling name: " << entry[i].bottleName << endl;
        outfile << "Bottled by: " << entry[i].distiller.name << " in ";
        outfile << entry[i].distiller.city << ", ";
        outfile << entry[i].distiller.state << endl;
        outfile << "Type: " << entry[i].type << endl;
        outfile << "Alcohol content: " << entry[i].alcohol.proof;
        outfile << " proof, " << entry[i].alcohol.percent<< "%" << endl;
        outfile << "Aged in " << entry[i].ageInfo.barrel << " barrels";
        if (entry[i].ageInfo.years > 0) {
            outfile << " for " << entry[i].ageInfo.years << " years";
            outfile << endl << endl;
        } else {
            outfile << endl << endl;
        }     
    }
    return;
}

/*
 Input: receives two parameters from the main program, an array of
  objects and n
 Process: will sort the array of objects in ascending order by proof
 Output: return to main program
 */
 void sort (katesWhiskey entry[], int n) {
    katesWhiskey temp;
    bool swaps;

    do {
        swaps = false;
        for (int pos = 0; pos < n-1; pos++) {
            if (entry[pos].alcohol.proof > entry[pos + 1].alcohol.proof) {
                temp = entry[pos];
                entry[pos] = entry[pos + 1];
                entry[pos + 1] = temp;
                swaps = true;
            }
        }
    } while (swaps);
    return;
 }

 /*
  Input: receives three parameters from the main program, an array of
   objects, n, and lookFor
  Process: searches the array of objects for the string that is stored in 
   lookFor
  Output: will print to file all occurrances of the string in lookFor
*/
void findType (katesWhiskey entry[], int n, string &lookFor) {
    bool found = false;

    infile >> lookFor;
    outfile << "Searching for " << lookFor << "..." << endl << endl;
    for (int i = 0; i < n; i++) {
        if (entry[i].type == lookFor) {
            outfile << lookFor << " found!" << endl;
            printone (entry[i]);
            found = true;
        }
        if (!found) {
            outfile << lookFor << " not found." << endl;
        }
    }
    return;
}
/*
 Input: receives one parameter from findType, a single element from an array
  of objects to be printed
 Process: will print all of the information for the object in the array that
  matched the value searched for in findType
 Output: return to findType function
*/
void printone (katesWhiskey entry) {
    outfile << "Bottling name: " << entry.bottleName << endl;
    outfile << "Bottled by: " << entry.distiller.name << " in ";
    outfile << entry.distiller.city << ", ";
    outfile << entry.distiller.state << endl;
    outfile << "Type: " << entry.type << endl;
    outfile << "Alcohol content: " << entry.alcohol.proof;
    outfile << " proof, " << entry.alcohol.percent<< "%" << endl;
    outfile << "Aged in " << entry.ageInfo.barrel << " barrels";
    if (entry.ageInfo.years > 0) {
        outfile << " for " << entry.ageInfo.years << " years";
        outfile << endl << endl;
    } else {
        outfile << endl << endl;
    }     
    return;
}