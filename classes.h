#ifndef PROJECT_CLASSES_H
#define PROJECT_CLASSES_H

#include <iostream>
using namespace std;

class sparePartNode;

class sparePart
{
private:
    string partName;
    int partNumber;
    float cost;
    bool existingPart;
public:
    sparePart(string pn, int pnum, float c, bool ep);
    void setPartName(string pn);
    void setPartNumber(int pnum);
    void setCost(float cost);
    void setExistingPart(bool ep);
    string getPartName();
    int getPartNumber();
    float getCost();
    bool getExistingPart();
    void getData();
    void putData();
    void modifyData();
};

class supplier {
private:
    string supplierName;
    int supplierCode;
    string supplierAddress;
    string supplierPhone;
    string supplierEmail;
public:
    supplier(string sn, int sc, string sa, string sp, string se);
    void setSupplierName(string sn);
    void setSupplierCode(int sc);
    void setSupplierAddress(string sa);
    void setSupplierPhone(string sp);
    void setSupplierEmail(string se);
    string getSupplierName();
    int getSupplierCode();
    string getSupplierAddress();
    string getSupplierPhone();
    string getSupplierEmail();
    void getData();
    void putData();
    void modifyData();
};

class supplierNode
{
private:
    supplier* data;
    supplierNode *left;
    supplierNode *right;
    sparePartNode *sparePartRoot;
public:
    supplierNode(supplier* d);
    void setdata(supplier* d);
    void setleft(supplierNode* l);
    void setright(supplierNode* r);
    void setsparePartRoot(sparePartNode* spr);
    supplier* getdata();
    supplierNode* getleft();
    supplierNode* getright();
    sparePartNode* getsparePartRoot();
    void addSparePart(sparePart* sp);
};

class node
{
private:
    string data;
    node *next;
public:
    node(string d);
    void setdata(string d);
    void setnext(node* next);
    string getdata();
    node* getnext();
};

class sparePartNode
{
private:
    sparePart* data;
    sparePartNode *left;
    sparePartNode *right;
    supplierNode *supplierRoot;
public:
    sparePartNode(sparePart* d);
    void setdata(sparePart* d);
    void setleft(sparePartNode* l);
    void setright(sparePartNode* r);
    void setsupplierRoot(supplierNode* sr);
    sparePart* getdata();
    sparePartNode* getleft();
    sparePartNode* getright();
    supplierNode* getsupplierRoot();
};

class sparePartTree
{
private:
    sparePartNode *root;
public:
    sparePartTree();
    void getSuccessor(sparePartNode* d, sparePartNode* &s);
    void insert();
    void remove(int pn);
    void search(int pn);
    void modify(int pn);
    void display(int pn);
    sparePartNode* searchNode(int pn);
    sparePartNode* searchNodeHelper(sparePartNode* currentNode, int pn);
};

class supplierTree
{
private:
    supplierNode *root;
public:
    supplierTree();
    void getSuccessor(supplierNode* d, supplierNode* &s);
    void insert();
    void remove(int sc);
    void search(int sc);
    void modify(int sc);
    void display(int sc);
    supplierNode* searchNode(int sc);
    supplierNode* searchNodeHelper(supplierNode* currentNode, int sc);
    bool searchbool(int sc);
    bool searchHelper(supplierNode* currentNode, int sc);
};

class stack
{
private:
    node *top;
public:
    stack();
    void push(string d);
    void pop();
    void display();
};

class queue
{
private:
    node *front;
    node *rear;
public:
    queue();
    void enqueue(string d);
    void dequeue();
    void display();
};

#endif //PROJECT_CLASSES_H
