//
//  main.cpp
//  SocialNetwork
//
//  Created by Nasim Mobasheri on 7/19/16.
//  Copyright © 2016 Nasim Mobasheri. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;




void freeNode();
void bfs ( int s , int numberOfNodes );


struct node                 // structure 1 to save noeds
{
    int nValue ;
    struct node *nextVertex ;
    int degree ;
    int visited ;
    int level;
    struct linkedList *adjacency ;
} Node;


struct linkedList           // structure 2 to save adjacencis verteces
{
    int nodeNumber;
    struct linkedList *adjacency;
}edge;

struct node *graph = NULL, *curVer = NULL, *curVer1 = NULL, *auxVer = NULL , *curVer3 = NULL;
struct linkedList *curVer2 = NULL , *auxVer2 = NULL , *curVer4 = NULL;


void bfs (int s , int numberOfNodes) ;


//                          ----------------------------------------
//                          ----------------------------------------
//                          ----------------------------------------



int main(int argc, const char * argv[])
{
   
 
  // Add a check for command line arguments
  if( 2 != argc ) {
    cout << "Usage: " << argv[0] << " <networ file name>" << endl;
    exit(-1);
  }
    
    
    //          Initial values  ----------------------------------------
    //                          ----------------------------------------
    
    edge.nodeNumber = -1;
    edge.adjacency = NULL;
    
    Node.nValue = -1;
    Node.nextVertex = NULL;
    Node.degree = 0;
    Node.visited = 0; //    not visited
    Node.level = -1;
    Node.adjacency = NULL;
    
    graph = (struct node *)malloc(sizeof(Node));
    
    graph->nValue = 1;
    graph->nextVertex = NULL;
    graph->degree = 0;
    graph->visited = 0;
    graph->level = -1;
    graph->adjacency = NULL;
    
    //                          ----------------------------------------
    //                          ----------------------------------------

    int source ;
    int target ;
    
    
    ifstream file ;
    file.open( argv[1] );
    
    if (!file) {
        cout << "Problem reading file"<<endl ;
        exit(1)    ;
    }
    
    
    
    
    
    
    int found = 0;
    int flagofViseversa ;
    int flagCase2 ;
    int flagCase1 ;
    int myFlag = 0 ;
    
   
    
    while(file >> source >> target)
    {
        
    
         
                found = 0;
                
                curVer = graph; // assigning first node myFlag checks if it's the first node
                if (!myFlag){
                    graph->nValue = source;
                    graph->nextVertex = NULL;
                    graph->degree = 0;
                    graph->visited = 0;
                    graph->level = -1;
                    graph->adjacency = NULL;
                    myFlag = 1;
                }
                if (myFlag){
                    
                    while (curVer != NULL) // search for the Vertex, exists or does not exist
                    {
                        if (curVer->nValue == source)
                        {
                            found = 1;
                            break;
                        }
                        auxVer = curVer;
                        curVer = curVer->nextVertex;
                    }
                    if (!found)
                    {
                        curVer = (struct node *)malloc(sizeof(Node));
                        curVer->nValue = source;
                        curVer->nextVertex = NULL;
                        curVer->adjacency = NULL;
                        curVer->degree = 0;
                        curVer->visited = 0;
                        curVer->level = -1;
                        auxVer->nextVertex = curVer;
                        
                    }
                }
        
        
                flagCase2 = 0 ;
                flagCase1 = 0 ;
        
                
                curVer2 = curVer->adjacency;
                
                if (curVer2 == NULL) // first edge you are adding for a node
                {
                    curVer2 = (struct linkedList *)malloc(sizeof(edge));
                    curVer2->nodeNumber = target;
                    curVer2->adjacency = NULL;
                    
                    curVer->adjacency = curVer2;
                }
                else // curVer2 is not NULL
                {
                    while (curVer2 != NULL)
                    {
                        if (curVer2->nodeNumber == target) {/// duplicate edges
                            flagCase2 = 1 ;
                            break ;
                        }
                        
                        auxVer2 = curVer2;
                        curVer2 = curVer2->adjacency;
                        
                    }
                    if (!flagCase2) {
                        
                        
                        curVer2 = (struct linkedList *)malloc(sizeof(edge));
                        curVer2->nodeNumber = target;
                        curVer2->adjacency = NULL;
                        auxVer2->adjacency = curVer2;
                    }
                }
                //////////////////
                
                curVer3 = graph ;
                while (curVer3!= NULL) {
                    
                    if (curVer3->nValue == target)
                    {
                        flagCase1 = 1;
                        break;
                    }
                    auxVer = curVer3;
                    curVer3 = curVer3->nextVertex;
                    
                }
                if (!flagCase1)
                {
                    curVer3 = (struct node *)malloc(sizeof(Node));
                    curVer3->nValue = target;
                    curVer3->nextVertex = NULL;
                    curVer3->adjacency = NULL;
                    curVer3->degree = 0;
                    curVer3->visited = 0;
                    curVer3->level = -1;
                    auxVer->nextVertex = curVer3;
                }
                
                
                
                
        flagofViseversa = 0 ;
        curVer4 = curVer3->adjacency;
        
        if (curVer4 == NULL)
        {
            curVer4 = (struct linkedList *)malloc(sizeof(edge));
            curVer4->nodeNumber = source;
            curVer4->adjacency = NULL;
            
            curVer3->adjacency = curVer4;
        }
        else // curVer2 is not NULL
        {
            while (curVer4 != NULL)
            {
                if (curVer4->nodeNumber == source) {/// ???????!!!!
                    flagofViseversa = 1 ;
                    break ;
                }
                
                auxVer2 = curVer4;
                curVer4 = curVer4->adjacency;
                
            }
            if (!flagofViseversa) {
                
                
                curVer4 = (struct linkedList *)malloc(sizeof(edge));
                curVer4->nodeNumber = source;
                curVer4->adjacency = NULL;
                auxVer2->adjacency = curVer4;
            }
        }
        
        
        
        
        
    }
    file.close();
    
    
    //*************************************************************************************\\
    
    int i , j ,  counter_for_degree = 0 ;
    int degreeCounter = 0 ;
    int numberOfNodes = 0;
    int arrayvalue ;
    int arrayHolder[numberOfNodes];
    curVer = graph;
    while (curVer != NULL)
    {
        
        ++numberOfNodes;
        
        arrayHolder[i] = curVer->nValue ;
        i++ ;
        curVer2 = curVer->adjacency;
        counter_for_degree = 0;
    //    cout << "\t" <<curVer->nValue;
        while (curVer2 != NULL)
        {
     //       cout << "\t"<<curVer2->nodeNumber;
            ++counter_for_degree;
            curVer->degree = counter_for_degree;
            curVer2 = curVer2->adjacency;
        }
    //    cout << "  >>>  deg:  lev:   vis: \t"<<curVer->degree << "\t"<<curVer->level <<"\t" << curVer->visited << endl;
        
        degreeCounter = degreeCounter + curVer->degree ;
        
        
        
        
        
        curVer = curVer->nextVertex;
    }
    
     int matrix[numberOfNodes][numberOfNodes];
    for (i=0; i<=numberOfNodes; i++) {
        
        arrayvalue = arrayHolder[i] ;
        bfs(arrayvalue, numberOfNodes);
        
        curVer =  graph;
        curVer1 = graph ;
        
    /*    while (curVer1 != NULL) {
            cout << "Bfs for" << arrayvalue << "\t" ;
            cout << "node #"<< curVer1->nValue<< "\t"<<curVer1->level ;
            curVer1 = curVer1->nextVertex ;
            cout<<endl ;
        }
        
      */  
        
        
        for (j=0; j<numberOfNodes; j++) {
            
            matrix[i][j]=curVer->level ;
            
            curVer = curVer->nextVertex;
        }//end of j
        
        for (int yy = 0 ; yy < numberOfNodes ; ++yy)
            matrix[yy][numberOfNodes-1] = matrix[numberOfNodes-1][yy];
        
        curVer1 = graph ;
        while (curVer1!= NULL) {
            curVer1->visited = 0 ;
            curVer1->level = -1;
            curVer1 = curVer1->nextVertex ;
        }
        
        
    }// end of for i
    
    
    
  
    
    
    
    curVer1 = graph ;
    while (curVer1 != NULL) {
        cout << curVer1->nValue << "\t" ;
        curVer2 = curVer1->adjacency;
        while (curVer2 != NULL) {
            cout << curVer2->nodeNumber<< ",";
            curVer2 = curVer2->adjacency ;
            
        }
        cout << endl ;
        curVer1 = curVer1->nextVertex ;
    }
    
    
    
    
    for (i=0; i<numberOfNodes; i++) {
        cout << endl ;
        for (j=0; j<numberOfNodes; j++) {
            cout << matrix[i][j] << "\t" ;
        }
    }
    
    
    
   //*************************************************************************************\\
    
    freeNode() ;
    cout << endl;
    return 0;
}



void freeNode() {

    curVer1 = graph ;
    while (curVer1 != NULL) {
        curVer2 = curVer1->adjacency;
        while (curVer2 != NULL) {
            auxVer2 = curVer2->adjacency;
            free(curVer2);
            curVer2 = auxVer2 ;
        }
        auxVer = curVer1->nextVertex ;
        free(curVer1);
        curVer1 = auxVer;
    }
    
}



void bfs ( int s , int numberOfNodes )
{
    int Q[numberOfNodes];
    int head = 0;
    int tail = 0;
    int sizeQ = 0; // tail - head;
    
    // _______________________________________________________________________
    // _______________________________________________________________________
    
    int i;
    int v;  //  temporary node to keep the head of the Q
    
    Q[tail] = s;            // put the source node in queue
    tail++;
    sizeQ = tail - head;   // update the size of queue
    
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    curVer = graph;
    while (curVer->nValue != s)
    {
        curVer = curVer->nextVertex;
        if (curVer == NULL )
            return ;
    }
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
    curVer->visited = 1;
    curVer->level = 0;         // update the first level in bfs
    
    while (sizeQ > 0) //1
    {
        v = Q[head];
        head++;
        sizeQ = tail - head;   // update the size of queue //
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        curVer = graph;
        while (curVer->nValue != v)
        {
            curVer = curVer->nextVertex;
        }
        curVer2 = curVer->adjacency;
        
        
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        // we should keep curVer->degree as v
        for (i = 1 ; i <= curVer->degree ; ++i) // for
        {
            
            //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            while (curVer2 != NULL)
            {
                int temp1;
                temp1 = curVer2->nodeNumber;
                
                //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                curVer1 = graph;
                while (curVer1->nValue != temp1)
                {
                    curVer1 = curVer1->nextVertex;
                }
                //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                int temp2;
                temp2 = curVer1->visited;
                if (!temp2)
                {
                    temp2 = 1;
                    curVer1->visited = temp2;
                    Q[tail] = temp1;
                    tail++;
                    sizeQ = tail - head;
                    
                    int temp3 = 0;
                    temp3 = curVer->level;
                    temp3++;
                    curVer1->level = temp3;
                }
                
                curVer2 = curVer2->adjacency;
            }
            //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        } //for
        sizeQ = tail - head;
    }//while 1
    
    
  
    
    return ;
}
//******************************************************************************************************
//*****
    
