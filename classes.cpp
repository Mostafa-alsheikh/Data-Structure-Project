#include "classes.h"

sparePart::sparePart(string pn, int pnum, float c, bool ep)
{
    partName = pn;
    partNumber = pnum;
    cost = c;
    existingPart = ep;
}
void sparePart::setPartName(string pn)
{
    partName = pn;
}
void sparePart::setPartNumber(int pnum)
{
    partNumber = pnum;
}
void sparePart::setCost(float c)
{
    cost = c;
}
void sparePart::setExistingPart(bool ep)
{
    existingPart = ep;
}
string sparePart::getPartName()
{
    return partName;
}
int sparePart::getPartNumber()
{
    return partNumber;
}
float sparePart::getCost()
{
    return cost;
}
bool sparePart::getExistingPart()
{
    return existingPart;
}
void sparePart::getData()
{
    cout << "Enter part name: ";
    cin >> partName;
    cout << "Enter part number: ";
    cin >> partNumber;
    cout << "Enter cost: ";
    cin >> cost;
    cout << "Enter 1 if part exists, 0 if not: ";
    cin >> existingPart;
}
void sparePart::putData()
{
    cout << "Part name: " << partName << endl;
    cout << "Part number: " << partNumber << endl;
    cout << "Cost: " << cost << endl;
    cout << "Part exists: " << existingPart << endl;
}
void sparePart::modifyData()
{
    cout << "Enter new part name: ";
    cin >> partName;
    cout << "Enter new cost: ";
    cin >> cost;
    cout << "Enter 1 if part exists, 0 if not: ";
    cin >> existingPart;
}
supplier::supplier(string sn, int sc, string sa, string sp, string se)
{
    supplierName = sn;
    supplierCode = sc;
    supplierAddress = sa;
    supplierPhone = sp;
    supplierEmail = se;
}
void supplier::setSupplierName(string sn)
{
    supplierName = sn;
}
void supplier::setSupplierCode(int sc)
{
    supplierCode = sc;
}
void supplier::setSupplierAddress(string sa)
{
    supplierAddress = sa;
}
void supplier::setSupplierPhone(string sp)
{
    supplierPhone = sp;
}
void supplier::setSupplierEmail(string se)
{
    supplierEmail = se;
}
string supplier::getSupplierName()
{
    return supplierName;
}
int supplier::getSupplierCode()
{
    return supplierCode;
}
string supplier::getSupplierAddress()
{
    return supplierAddress;
}
string supplier::getSupplierPhone()
{
    return supplierPhone;
}
string supplier::getSupplierEmail()
{
    return supplierEmail;
}
void supplier::getData()
{
    supplierTree ST;

    cout << "Enter supplier name: ";
    cin >> supplierName;
     do
    {
        cout << "Enter supplier code: ";
        cin >> supplierCode;

        // Check if the supplier code already exists in the tree
        if (ST.searchbool(supplierCode))
        {
            cout << "Supplier code already exists. Please enter a unique code." << endl;
        }

    } while (ST.searchbool(supplierCode));
    cout << "Enter supplier address: ";
    cin >> supplierAddress;
    cout << "Enter supplier phone: ";
    cin >> supplierPhone;
    cout << "Enter supplier email: ";
    cin >> supplierEmail;
}
void supplier::putData()
{
    cout << "Supplier name: " << supplierName << endl;
    cout << "Supplier code: " << supplierCode << endl;
    cout << "Supplier address: " << supplierAddress << endl;
    cout << "Supplier phone: " << supplierPhone << endl;
    cout << "Supplier email: " << supplierEmail << endl;
}
void supplier::modifyData()
{
    cout << "Enter new supplier name: ";
    cin >> supplierName;
    cout << "Enter new supplier address: ";
    cin >> supplierAddress;
    cout << "Enter new supplier phone: ";
    cin >> supplierPhone;
    cout << "Enter new supplier email: ";
    cin >> supplierEmail;
}
supplierNode::supplierNode(supplier* d)
{
    data = d;
    left = NULL;
    right = NULL;
    sparePartRoot = NULL;
}
void supplierNode::setdata(supplier* d)
{
    data = d;
}
void supplierNode::setleft(supplierNode* l)
{
    left = l;
}
void supplierNode::setright(supplierNode* r)
{
    right = r;
}
void supplierNode::setsparePartRoot(sparePartNode* spt)
{
    sparePartRoot = spt;
}
supplier* supplierNode::getdata()
{
    return data;
}
supplierNode* supplierNode::getleft()
{
    return left;
}
supplierNode* supplierNode::getright()
{
    return right;
}
void supplierNode::addSparePart(sparePart* sp)
    {
        sparePartNode* newSparePartNode = new sparePartNode(sp);
        newSparePartNode->setsupplierRoot(this);

        // Add the spare part to the linked list
        if (sparePartRoot == nullptr)
        {
            sparePartRoot = newSparePartNode;
        }
        else
        {
            sparePartNode* current = sparePartRoot;
            while (current->getright() != nullptr)
            {
                current = current->getright();
            }
            current->setright(newSparePartNode);
        }
    }
sparePartNode* supplierNode::getsparePartRoot()
{
    return sparePartRoot;
}
sparePartNode::sparePartNode(sparePart* d)
{
    data = d;
    left = NULL;
    right = NULL;
    supplierRoot = NULL;
}
void sparePartNode::setdata(sparePart* d)
{
    data = d;
}
void sparePartNode::setleft(sparePartNode* l)
{
    left = l;
}
void sparePartNode::setright(sparePartNode* r)
{
    right = r;
}
void sparePartNode::setsupplierRoot(supplierNode* sr)
{
    supplierRoot = sr;
}
sparePart* sparePartNode::getdata()
{
    return data;
}
sparePartNode* sparePartNode::getleft()
{
    return left;
}
sparePartNode* sparePartNode::getright()
{
    return right;
}
supplierNode* sparePartNode::getsupplierRoot()
{
    return supplierRoot;
}
sparePartTree::sparePartTree()
{
    root = NULL;
}
void sparePartTree::getSuccessor(sparePartNode* d, sparePartNode* &s)
{
    s = d->getright();
    while (s->getleft() != NULL)
    {
        s = s->getleft();
    }
}

void sparePartTree::insert()
{
    sparePartNode* newNode = new sparePartNode(new sparePart("", 0, 0.0, false));
    newNode->getdata()->getData(); // Get data from the user
    if (root == NULL)
    {
        root = newNode;
    }
    else
    {
        sparePartNode* current = root;
        sparePartNode* parent;
        while (true)
        {
            parent = current;
            if (newNode->getdata()->getPartNumber() < current->getdata()->getPartNumber())
            {
                current = current->getleft();
                if (current == NULL)
                {
                    parent->setleft(newNode);
                    return;
                }
            }
            else
            {
                current = current->getright();
                if (current == NULL)
                {
                    parent->setright(newNode);
                    return;
                }
            }
        }
    }
}

void sparePartTree::remove(int pn)
{
    // Implement spare part removal logic
    sparePartNode* current = root;
    sparePartNode* parent = NULL;
    bool isLeftChild = true;

    while (current->getdata()->getPartNumber() != pn)
    {
        parent = current;

        if (pn < current->getdata()->getPartNumber())
        {
            current = current->getleft();
            isLeftChild = true;
        }
        else
        {
            current = current->getright();
            isLeftChild = false;
        }

        if (current == NULL)
        {
            cout << "Spare Part not found." << endl;
            return;
        }
    }

    // Node found, now handle removal cases
    if (current->getleft() == NULL && current->getright() == NULL)
    {
        // Case 1: No children
        if (current == root)
        {
            root = NULL;
        }
        else if (isLeftChild)
        {
            parent->setleft(NULL);
        }
        else
        {
            parent->setright(NULL);
        }
    }
    else if (current->getright() == NULL)
    {
        // Case 2: One child (left)
        if (current == root)
        {
            root = current->getleft();
        }
        else if (isLeftChild)
        {
            parent->setleft(current->getleft());
        }
        else
        {
            parent->setright(current->getleft());
        }
    }
    else if (current->getleft() == NULL)
    {
        // Case 2: One child (right)
        if (current == root)
        {
            root = current->getright();
        }
        else if (isLeftChild)
        {
            parent->setleft(current->getright());
        }
        else
        {
            parent->setright(current->getright());
        }
    }
    else
    {
        // Case 3: Two children
        sparePartNode* successor;
        getSuccessor(current, successor);
        if (current == root)
        {
            root = successor;
        }
        else if (isLeftChild)
        {
            parent->setleft(successor);
        }
        else
        {
            parent->setright(successor);
        }
        successor->setleft(current->getleft());
    }

    delete current;
    cout << "Spare Part with Part Number " << pn << " deleted." << endl;
}

void sparePartTree::search(int pn)
{
    // Implement spare part search logic
    sparePartNode* current = root;

    while (current != NULL && current->getdata()->getPartNumber() != pn)
    {
        if (pn < current->getdata()->getPartNumber())
        {
            current = current->getleft();
        }
        else
        {
            current = current->getright();
        }
    }

    if (current != NULL)
    {
        cout << "Spare Part found:" << endl;
        current->getdata()->putData();
    }
    else
    {
        cout << "Spare Part not found." << endl;
    }
}

supplierNode* supplierTree::searchNode(int sc)
{
    return searchNodeHelper(root, sc);
}

supplierNode* supplierTree::searchNodeHelper(supplierNode* currentNode, int sc)
{
    if (currentNode == nullptr || currentNode->getdata()->getSupplierCode() == sc)
    {
        return currentNode;
    }

    if (sc < currentNode->getdata()->getSupplierCode())
    {
        return searchNodeHelper(currentNode->getleft(), sc);
    }
    else
    {
        return searchNodeHelper(currentNode->getright(), sc);
    }
}

void sparePartTree::modify(int pn)
{
    // Implement spare part modification logic
    sparePartNode* current = root;

    while (current != NULL && current->getdata()->getPartNumber() != pn)
    {
        if (pn < current->getdata()->getPartNumber())
        {
            current = current->getleft();
        }
        else
        {
            current = current->getright();
        }
    }

    if (current != NULL)
    {
        cout << "Enter new data for Spare Part:" << endl;
        current->getdata()->modifyData();
        cout << "Spare Part data modified successfully." << endl;
    }
    else
    {
        cout << "Spare Part not found. Cannot modify." << endl;
    }
}

sparePartNode* sparePartTree::searchNode(int pn)
{
    return searchNodeHelper(root, pn);
}

sparePartNode* sparePartTree::searchNodeHelper(sparePartNode* currentNode, int pn)
{
    if (currentNode == nullptr || currentNode->getdata()->getPartNumber() == pn)
    {
        return currentNode;
    }

    if (pn < currentNode->getdata()->getPartNumber())
    {
        return searchNodeHelper(currentNode->getleft(), pn);
    }
    else
    {
        return searchNodeHelper(currentNode->getright(), pn);
    }
}

void sparePartTree::display(int pn)
{
    // Implement spare part display logic
    sparePartNode* current = root;

    while (current != NULL && current->getdata()->getPartNumber() != pn)
    {
        if (pn < current->getdata()->getPartNumber())
        {
            current = current->getleft();
        }
        else
        {
            current = current->getright();
        }
    }

    if (current != NULL)
    {
        current->getdata()->putData();
    }
    else
    {
        cout << "Spare Part not found." << endl;
    }
}
void supplierTree::getSuccessor(supplierNode* d, supplierNode* &s)
{
    s = d->getright();
    while (s->getleft() != NULL)
    {
        s = s->getleft();
    }
}

void supplierTree::insert()
{
    supplierNode* newNode = new supplierNode(new supplier("", 0, "", "", ""));
    newNode->getdata()->getData(); // Get data from the user
    if (root == NULL)
    {
        root = newNode;
    }
    else
    {
        supplierNode* current = root;
        supplierNode* parent;
        while (true)
        {
            parent = current;
            if (newNode->getdata()->getSupplierCode() < current->getdata()->getSupplierCode())
            {
                current = current->getleft();
                if (current == NULL)
                {
                    parent->setleft(newNode);
                    return;
                }
            }
            else
            {
                current = current->getright();
                if (current == NULL)
                {
                    parent->setright(newNode);
                    return;
                }
            }
        }
    }
}

void supplierTree::remove(int sc)
{
    // Implement supplier removal logic
    supplierNode* current = root;
    supplierNode* parent = NULL;
    bool isLeftChild = true;

    while (current->getdata()->getSupplierCode() != sc)
    {
        parent = current;

        if (sc < current->getdata()->getSupplierCode())
        {
            current = current->getleft();
            isLeftChild = true;
        }
        else
        {
            current = current->getright();
            isLeftChild = false;
        }

        if (current == NULL)
        {
            cout << "Supplier not found." << endl;
            return;
        }
    }

    // Node found, now handle removal cases
    if (current->getleft() == NULL && current->getright() == NULL)
    {
        // Case 1: No children
        if (current == root)
        {
            root = NULL;
        }
        else if (isLeftChild)
        {
            parent->setleft(NULL);
        }
        else
        {
            parent->setright(NULL);
        }
    }
    else if (current->getright() == NULL)
    {
        // Case 2: One child (left)
        if (current == root)
        {
            root = current->getleft();
        }
        else if (isLeftChild)
        {
            parent->setleft(current->getleft());
        }
        else
        {
            parent->setright(current->getleft());
        }
    }
    else if (current->getleft() == NULL)
    {
        // Case 2: One child (right)
        if (current == root)
        {
            root = current->getright();
        }
        else if (isLeftChild)
        {
            parent->setleft(current->getright());
        }
        else
        {
            parent->setright(current->getright());
        }
    }
    else
    {
        // Case 3: Two children
        supplierNode* successor;
        getSuccessor(current, successor);
        if (current == root)
        {
            root = successor;
        }
        else if (isLeftChild)
        {
            parent->setleft(successor);
        }
        else
        {
            parent->setright(successor);
        }
        successor->setleft(current->getleft());
    }

    delete current;
    cout << "Supplier with Code " << sc << " deleted." << endl;
}

void supplierTree::search(int sc)
{
    // Implement supplier search logic
    supplierNode* current = root;

    while (current != NULL && current->getdata()->getSupplierCode() != sc)
    {
        if (sc < current->getdata()->getSupplierCode())
        {
            current = current->getleft();
        }
        else
        {
            current = current->getright();
        }
    }

    if (current != NULL)
    {
        cout << "Supplier found:" << endl;
        current->getdata()->putData();
    }
    else
    {
        cout << "Supplier not found." << endl;
    }
}

bool supplierTree::searchbool(int sc)
{
    return searchHelper(root, sc);
}

bool supplierTree::searchHelper(supplierNode* currentNode, int sc)
{
    while (currentNode != nullptr)
    {
        if (sc == currentNode->getdata()->getSupplierCode())
        {
            return true;  // Supplier code found
        }
        else if (sc < currentNode->getdata()->getSupplierCode())
        {
            currentNode = currentNode->getleft();
        }
        else
        {
            currentNode = currentNode->getright();
        }
    }

    return false;  // Supplier code not found
}

void supplierTree::modify(int sc)
{
    // Implement supplier modification logic
    supplierNode* current = root;

    while (current != NULL && current->getdata()->getSupplierCode() != sc)
    {
        if (sc < current->getdata()->getSupplierCode())
        {
            current = current->getleft();
        }
        else
        {
            current = current->getright();
        }
    }

    if (current != NULL)
    {
        cout << "Enter new data for Supplier:" << endl;
        current->getdata()->modifyData();
        cout << "Supplier data modified successfully." << endl;
    }
    else
    {
        cout << "Supplier not found. Cannot modify." << endl;
    }
}

void supplierTree::display(int sc)
{
    // Implement supplier display logic
    supplierNode* current = root;

    while (current != NULL && current->getdata()->getSupplierCode() != sc)
    {
        if (sc < current->getdata()->getSupplierCode())
        {
            current = current->getleft();
        }
        else
        {
            current = current->getright();
        }
    }

    if (current != NULL)
    {
        current->getdata()->putData();
    }
    else
    {
        cout << "Supplier not found." << endl;
    }
}

supplierTree::supplierTree()
{
    root = NULL;
}

node :: node(string d)
{
    data = d;
    next = NULL;
}
void node :: setdata(string d)
{
    data = d;
}
void node :: setnext(node* next)
{
    this->next = next;
}
string node :: getdata()
{
    return data;
}
node* node :: getnext()
{
    return next;
}
stack :: stack()
{
    top = NULL;
}
void stack :: push(string d)
{
    node *newNode = new node(d);
    newNode->setnext(top);
    top = newNode;
}
void stack :: pop()
{
    if (top == NULL)
    {
        cout << "Stack is empty." << endl;
    }
    else
    {
        node *temp = top;
        top = top->getnext();
        delete temp;
    }
}
queue :: queue()
{
    front = NULL;
    rear = NULL;
}
void queue :: enqueue(string d)
{
    node *newNode = new node(d);
    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->setnext(newNode);
        rear = newNode;
    }
}
void queue :: dequeue()
{
    if (front == NULL)
    {
        cout << "Queue is empty." << endl;
    }
    else
    {
        node *temp = front;
        front = front->getnext();
        delete temp;
    }
}
void stack :: display()
{
    if (top == NULL)
    {
        cout << "Stack is empty." << endl;
    }
    else
    {
        node *current = top;
        while (current != NULL)
        {
            cout << (current->getdata()) << endl;
            current = current->getnext();
        }
    }
}
void queue :: display()
{
    if (front == NULL)
    {
        cout << "Queue is empty." << endl;
    }
    else
    {
        node *current = front;
        while (current != NULL)
        {
            cout << (current->getdata()) << endl;
            current = current->getnext();
        }
    }
}
