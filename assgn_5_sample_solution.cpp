// Name: Aryan Goenka
// Roll: 21IE10006
// Assign no: 5

#include <iostream>
#include <iomanip>
using namespace std;

// Defining structures
typedef struct{
	string name;
	int roll;
	float cgpa;
}record;

#define MAX 100
typedef struct node_name{
	string name;
	struct node_name *left, *right;
	record *data;
	char balance;	// balance = height(left) - height(right)
}node_name;

typedef struct node_roll{
	int roll;
	struct node_roll *left, *right;
	record *data;
	char balance;
}node_roll;

typedef struct node_cgpa{
	float cgpa;
	struct node_cgpa *left, *right;
	record *data;
	char balance;
}node_cgpa;

/* In balance,
	a = -1
	b = 0
	c = 1
   these are representations being used
*/

// Functions to add new node to respective AVL trees
node_name *newNodeName(string name, record *data){
	node_name *node = new node_name();
	node->name = name;
	node->left = NULL;
	node->right = NULL;
	node->data = data;
	node->balance = 'b';
    
	return (node);
}

node_roll *newNodeRoll(int roll, record *data){
	node_roll *node = new node_roll();
	node->roll = roll;
	node->left = NULL;
	node->right = NULL;
	node->data = data;
	node->balance = 'b';

	return (node);
}

node_cgpa *newNodeCgpa(float cgpa, record *data)
{
    node_cgpa *node = new node_cgpa();
    node->cgpa = cgpa;
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    node->balance = 'b';
    
    return (node);
}

// Rotate functions
// (name)
node_name *leftRotateName(node_name *g){
	node_name *p = g->right;
	node_name *q = p->left;

	p->left = g;
	g->right = q;

	// Updating the balance
	(p->balance)++;
	(g->balance)++;

	return p;
}

node_name *rightRotateName(node_name *g){
	node_name *p = g->left;
	node_name *q = p->right;

	p->right = g;
	g->left = q;
	
	// Updating the balance
	(p->balance)--;
	(g->balance)--;

	return p;
}

// (roll)
node_roll *leftRotateRoll(node_roll *g){
	node_roll *p = g->right;
	node_roll *q = p->left;

	p->left = g;
	g->right = q;

	// Updating the balance
	(p->balance)++;
	(g->balance)++;

	return p;
}

node_roll *rightRotateRoll(node_roll *g){
	node_roll *p = g->left;
	node_roll *q = p->right;

	p->right = g;
	g->left = q;
	
	// Updating the balance
	(p->balance)--;
	(g->balance)--;

	return p;
}

// (cgpa)
node_cgpa *leftRotateCgpa(node_cgpa *g){
	node_cgpa *p = g->right;
	node_cgpa *q = p->left;

	p->left = g;
	g->right = q;

	// Updating the balance
	(p->balance)++;
	(g->balance)++;

	return p;
}

node_cgpa *rightRotateCgpa(node_cgpa *g){
	node_cgpa *p = g->left;
	node_cgpa *q = p->right;

	p->right = g;
	g->left = q;
	
	// Updating the balance
	(p->balance)--;
	(g->balance)--;

	return p;
}


// Insert Functions for respective AVL trees
// (name)
node_name *insertName(node_name *node, record * data)
{
	string name = data->name;
	int flag = 0;	// to keep track if node was present already or is inserted
	
	// normal BST insertion
	if (node == NULL){
		flag = 1;
		return (newNodeName(name, data));
	}
	if (name < node->name){
		node->left = insertName(node->left, data);
	}
	else if(name > node->name){
		node->right = insertName(node->right, data);
	}
	else{
		return node;
	}
	
	char balance = node->balance;

	if(flag == 1){
		// Left Left Case
		if (balance > 'c' && name < node->left->name){
			return rightRotateName(node);
		}

		// Right Right Case
		if (balance < 'a' && name > node->right->name){
			return leftRotateName(node);
		}

		// Left Right Case
		if (balance > 'c' && name > node->left->name)
		{
			node->left = leftRotateName(node->left);
			return rightRotateName(node);
		}

		// Right Left Case
		if (balance < 'a' && name < node->right->name)
		{
			node->right = rightRotateName(node->right);
			return leftRotateName(node);
		}
	}

	return node;
}

// (roll)
node_roll *insertRoll(node_roll *node, record * data)
{
	int roll = data->roll;
	int flag = 0;	// to keep track if node was present already or is inserted
	
	// normal BST insertion
	if (node == NULL){
		flag = 1;
		return (newNodeRoll(roll, data));
	}
	if (roll < node->roll){
		node->left = insertRoll(node->left, data);
	}
	else if(roll > node->roll){
		node->right = insertRoll(node->right, data);
	}
	else{
		return node;
	}

	char balance = node->balance;

	if(flag == 1){
		// Left Left Case
		if (balance > 'c' && roll < node->left->roll){
			return rightRotateRoll(node);
		}

		// Right Right Case
		if (balance < 'a' && roll > node->right->roll){
			return leftRotateRoll(node);
		}

		// Left Right Case
		if (balance > 'c' && roll > node->left->roll)
		{
			node->left = leftRotateRoll(node->left);
			return rightRotateRoll(node);
		}

		// Right Left Case
		if (balance < 'a' && roll < node->right->roll)
		{
			node->right = rightRotateRoll(node->right);
			return leftRotateRoll(node);
		}
	}

	return node;
}

// (cgpa)
node_cgpa *insertCgpa(node_cgpa *node, record * data)
{
	float cgpa = data->cgpa;
	int flag = 0;	// to keep track if node was present already or is inserted
	
	// normal BST insertion
	if (node == NULL){
		flag = 1;
		return (newNodeCgpa(cgpa, data));
	}
	if (cgpa < node->cgpa){
		node->left = insertCgpa(node->left, data);
	}
	else if(cgpa > node->cgpa){
		node->right = insertCgpa(node->right, data);
	}
	else{
		return node;
	}
	
	char balance = node->balance;

	if(flag == 1){
		// Left Left Case
		if (balance > 'c' && cgpa < node->left->cgpa){
			return rightRotateCgpa(node);
		}

		// Right Right Case
		if (balance < 'a' && cgpa > node->right->cgpa){
			return leftRotateCgpa(node);
		}

		// Left Right Case
		if (balance > 'c' && cgpa > node->left->cgpa)
		{
			node->left = leftRotateCgpa(node->left);
			return rightRotateCgpa(node);
		}

		// Right Left Case
		if (balance < 'a' && cgpa < node->right->cgpa)
		{
			node->right = rightRotateCgpa(node->right);
			return leftRotateCgpa(node);
		}
	}

	return node;
}

// Print data
void printdata(record * data){
	cout << "(" << data-> name << ", " << data-> roll << ", ";
	cout << fixed << setprecision(2) << data-> cgpa<< "),";
}


// Functions for printing in Ascending order
// (name)

void printNameAsc(node_name *root){
	if (root != NULL)
	{
		printNameAsc(root->left);
		printdata(root->data);
		printNameAsc(root->right);
	}
}

// (Roll)
void printRollAsc(node_roll *root){
	if (root != NULL)
	{
		printRollAsc(root->left);
		printdata(root->data);
		printRollAsc(root->right);
	}
}

// (cgpa)
void printCgpaAsc(node_cgpa *root){
	if (root != NULL)
	{
		printCgpaAsc(root->left);
		printdata(root->data);
		printCgpaAsc(root->right);
	}
}

// Functions for printing in Descending order
// (name)

void printNameDsc(node_name *root){
	if (root != NULL)
	{
		printNameDsc(root->right);
		printdata(root->data);
		printNameDsc(root->left);
	}
}

// (Roll)
void printRollDsc(node_roll *root){
	if (root != NULL)
	{
		printRollDsc(root->right);
		printdata(root->data);
		printRollDsc(root->left);
	}
}

// (cgpa)
void printCgpaDsc(node_cgpa *root){
	if (root != NULL)
	{
		printCgpaDsc(root->right);
		printdata(root->data);
		printCgpaDsc(root->left);
	}
}

// Functions to Search for a record
// (name)
node_name *searchName(node_name *node, string name){
	if(node == NULL){
		cout << "No record found for " << name;
		return NULL;
	}
	if (node->name == name){
		printdata(node->data);
		return NULL;
	}
	if (name < node->name){
		node->left = searchName(node->left, name);
	}
	else if(name > node->name){
		node->right = searchName(node->right, name);
	}
	else{	// node not found, i.e. returning NULL
		cout << "No record found for " << name;
		return NULL;
	}
}

// (roll)
node_roll *searchRoll(node_roll *node, int roll){
	if(node == NULL){
		cout << "No record found for " << roll;
		return NULL;
	}
	if (node->roll == roll){
		printdata(node->data);
		return NULL;
	}
	if (roll < node->roll){
		node->left = searchRoll(node->left, roll);
	}
	else if(roll > node->roll){
		node->right = searchRoll(node->right, roll);
	}
	else{	// node not found, i.e. returning NULL
		cout << "No record found for " << roll;
		return NULL;
	}
}

// (cgpa)
node_cgpa *searchCgpa(node_cgpa *node, float cgpa){
	if(node == NULL){
		cout << "No record found for ";
		cout << fixed << setprecision(2) << cgpa;
		return NULL;
	}
	if (node->cgpa == cgpa){
		printdata(node->data);
		return NULL;
	}
	if (cgpa < node->cgpa){
		node->left = searchCgpa(node->left, cgpa);
	}
	else if(cgpa > node->cgpa){
		node->right = searchCgpa(node->right, cgpa);
	}
	else{	// node not found, i.e. returning NULL
		cout << "No record found for ";
		cout << fixed << setprecision(2) << cgpa;
		return NULL;
	}
}

// Function to delete by name



int main(){
	cout << "1.insert\n2. delete by name\n3. search by name\n4. search by roll\n5. search by cgpa\n";
	cout << "6. Print ascending by name\n7. Print descending by name\n8. Print ascending by roll\n9. Print descending by roll\n";
	cout << "10. Print ascending by cgpa\n11. Print descending by cgpa\n12. Exit\n";
	
	
	
	int N;
	cout << "\nChoose option: ";
	cin >> N;
	
	record data[100];
	int i=0;
	
	node_name* rootName = NULL;
	node_roll* rootRoll = NULL;
	node_cgpa* rootCgpa= NULL;
	
	while(N!=12){
		if(N==1){
			cout << "Write name: ";
			cin >> data[i].name;
			cout << "Write roll: ";
			cin >> data[i].roll;
			cout << "Write CGPA: ";
			cin >> data[i].cgpa;
			
			rootName = insertName(rootName, &data[i]);
			rootRoll = insertRoll(rootRoll, &data[i]);
			rootCgpa = insertCgpa(rootCgpa, &data[i]);
			
			i++;
		}else if(N==2){
			cout << "I was not able to complete the delete function in time" << endl;
		}else if(N==3){
			string name;
			cout << "Write name: ";
			cin >> name;
			
			searchName(rootName, name);
		}else if(N==4){
			int roll;
			cout << "Write roll: ";
			cin >> roll;
			
			searchRoll(rootRoll, roll);
		}else if(N==5){
			float cgpa;
			cout << "Write cgpa: ";
			cin >> cgpa;
			
			searchCgpa(rootCgpa, cgpa);
		}else if(N==6){
			printNameAsc(rootName);
		}else if(N==7){
			printNameDsc(rootName);
		}else if(N==8){
			printRollAsc(rootRoll);
		}else if(N==9){
			printRollDsc(rootRoll);
		}else if(N==10){
			printCgpaAsc(rootCgpa);
		}else if(N==11){
			printCgpaDsc(rootCgpa);
		}else{
			break;
		}
		
		cout << "Choose option: ";
		cin >> N;
	}
	
	cout << "Program exits\n";
	
	return 0;
}
