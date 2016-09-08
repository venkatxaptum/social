//
//  main.cpp
//  test2
//
//  Created by Nasim Mobasheri on 8/28/16.
//  Copyright © 2016 Nasim Mobasheri. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <limits.h>
#include<vector>
#include <algorithm>

using namespace std;









int findmin(int *a , int size) {
    int min;
    int i =0;
    min = a[0];
    for (i=0; i< size; i++) {
        
        if (a[i] < min) {
            min = a[i] ;
        }
    }
    





    return min ;
}



int indexfinder (int *a , int size, int tar){
    int index = 0;
    for (int i = 0 ; i<size; i++) {
        if (a[i] == tar) {
            index = i ;
        }
    }


    return  index;
}



int main(int argc, const char * argv[]) {
   
    
    
    //int numberOfNodes = 12 ;
  /*  int matrix[12][12]={{0,1,3,4,4,1,1,2,2,3,2,5},{1,0,3,4,4,1,2,2,2,3,1,5},{3,3,0,1,2,2,4,2,1,1,3,3},
        {4,4,1,0,1,3,5,2,2,1,3,2},{4,4,2,1,0,3,5,2,3,1,3,1},{1,1,2,3,3,0,2,1,1,2,2,4},{1,2,4,5,5,2,0,3,3,4,3,6},{2,2,2,2,2,1,3,0,2,1,1,3},{2,2,1,2,3,1,3,2,0,2,3,4},{3,3,1,1,1,2,4,1,2,0,2,2},{2,1,3,3,3,2,3,1,3,2,0,4}, {5,5,3,2,1,4,6,3,4,2,4,0}};
   
   int arrayHolder[12] = {0,1,2,3,4,5,6,7,8,9, 12, 13} ; //
    
    */
    int numberOfNodes = 6 ;
    int arrayHolder[6]  = {0,1,2,3,4,6};
    int matrix[6][6] = {{0,1,2,2,3,3},{1,0,1,1,2,2},{2,1,0,1,1,1},{2,1,1,0,2,2},{3,2,1,2,0,1},{3,2,1,2,1,0}} ;
    
    
    
    int l_opt = std::numeric_limits<int>::max(); // setting the size of V-opt to infinity 
    int ka =  2 ; // K 
    
    int counterdif =0 ; // this integer hold the size of V-Vprime in our loops 
    
  
    
    vector<int> Vprim ; //create the initial set for Vprime
    vector<int> v_opt ; // V-opt: our final set, if empty it shows there is no set for that value of K


	// Start of our main loop, for every node in our set we will run this algorithm and find the min  V-opt 
    for (int k = 0; k <numberOfNodes ; k++) {
        
        int checkflag = 0; //done flag
        int sizeboun = 0 ; // this variable contains Vprime size 
        int counterdup = 0 ;
        int miu = 0 ;  
        int testval =0 ;
        int counter_o_vector =0 ;
  
        // by start of each iteration add v[k] that is stored in arrayholder to Vprime 
        
     
        Vprim.push_back(arrayHolder[k]);
        sizeboun = Vprim.size() ;
        
  
     
        
       
        // as long as V-Vprime is not empty and we have not found a set 
        while (Vprim.size() < numberOfNodes && checkflag != 1) {
             std:: vector<vector<int>> setd;  // create a vector of vectors to hold values of D 
            int counter_row = 0; // this variable ensures that in iteration our set does not make more subsets 
            counterdif = numberOfNodes - Vprim.size();
            
             
        int arraydup [counterdif] ; //this array is used to store set duplicates for calculating miu 
        int valholder[counterdif] ; // this array holds  all members of V-Vprim
         
            int   iter2index =0 ; // find the index of nodenumber 
            
            
            //compute setddd
           for (int iter2 =0 ; iter2 < Vprim.size(); iter2++){
            
               iter2index = indexfinder(arrayHolder , numberOfNodes , Vprim.at(iter2)); // find the  correct index for accessing the matrix 
               counter_o_vector = 0 ; // prevent extra subsets 
               vector<int> newCol ;
               
        
               for (int iter1 =0 ; iter1 < numberOfNodes; iter1++)  {
                   
                  
                  // Check and make sure that Setd only accepts values from V-Vprim 
            
                   if(!(std:: find(Vprim.begin(), Vprim.end(), arrayHolder[iter1]) != Vprim.end())){
                       
                       // no extra subset 
                       if (counter_row < counterdif) {
                            setd.push_back(newCol);
                       }
                       counter_row ++ ;
                      
					   // distance of two selected nodes, one from Vprim one from V-vprim
                       testval = matrix[iter1][iter2index] ;
                       
                       setd[counter_o_vector].push_back(testval);
                       valholder[counter_o_vector] = arrayHolder[iter1] ;
                       ++counter_o_vector ;
                       
                    }//end of inner if
              
                    
                    
                   // }
                }//end of iter2
            }//end of iter1
            
            
            
            //compute miu 
           
            
            // check for all similar subsets and keep count 
            
            for (int iter3 =0; iter3 < counterdif; iter3++) {
                counterdup = 1 ; //to count for elemet too
               
                for (int iter4 =0 ; iter4 < counterdif; iter4++) {
                       

                    if (setd[iter3] == setd[iter4] && iter3 != iter4) {
                        counterdup ++ ;
                    } // end of if
                    
                        
                        
                } ///end of iter4
                arraydup[iter3] = counterdup ;
              
            }//end of iter3

			//arraydup is an array of all equal subset   
         
            miu = findmin (arraydup , counterdif);
            
            // start comparison
            if (miu >= ka && Vprim.size()< l_opt) {
                l_opt = Vprim.size() ;
                checkflag = 1 ;
               
                v_opt = Vprim ;
                
                
            }//end of if miu
			// add every node that the count = miu to vprim 
            else{
                for (int iter6=0; iter6 < counterdif; ++iter6) {
                    if (arraydup[iter6]== miu) {
                     
                        Vprim.push_back(valholder[iter6]) ;
                    }
                }
            
            
            }
                
            
        } // end of while
        
        
        Vprim.clear() ;
        
      
        
        
    } //end of for
    
    
    cout<< "this is l-opt = "<<l_opt<<endl ;
    cout << "opt set is :  " ;
    for (std::vector<int>:: iterator myiter = v_opt.begin(); myiter != v_opt.end(); myiter++) {
        cout<< *myiter <<"," ;
    
    }
    
    //*/
    
    return 0;
}





