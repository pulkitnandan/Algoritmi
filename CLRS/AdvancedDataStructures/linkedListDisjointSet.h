/*Owned from http://www.cplusplus.com/articles/Lw6AC542/ Thanks Mr. Closed Account S6k9GNh0*/

template <typename T>
class List;

template <typename T>
class Set;

template <class TNode>
class Iterator
{
	/* Helper class to provide pointer like facilities around a node */
	friend class List<typename TNode::value_type>;
	TNode* pNode; //The node oriented with this instance of iterator.
	
	Iterator(TNode* _pNode) : pNode(_pNode) {}
public:
	void operator++(){ pNode = pNode->_next; }
	void operator++(int){ pNode = pNode->_next; }
	bool operator!=(Iterator<TNode> rval){ return !(pNode == rval.pNode); }
	bool operator==(Iterator<TNode> rval){ return (pNode == rval.pNode); }
	typename TNode::value_type operator*(){	return pNode->_data; }
	Iterator<TNode> operator+(int _i)
	{
		Iterator<TNode> iter = *this;
		for (int i = 0; i < _i; ++i)
		{
			if (iter.pNode) //If there's something to move onto...
				++iter;
			else
				break;
		}
		return iter; //Return regardless of whether its valid...
	}
};

template <typename T>
class Node
{
	friend class List<T>;
	friend class Iterator<Node<T> >;
	Node () : _next(0) {}
	Node (T data) : _data(data), _next(0), _head(0) {}
	Node (T data, Node<T>* next) : _data(data), _next(next){}
	Node (T data, Node<T>* next, Node<T>* head) : _data(data), _next(next), _head(head){}
	Node (Node<T>* next) : _next(next) {}
	Node (Node<T>* next, Node<T>* head) : _next(head), _head(head) {}

	T _data;
	Node<T>* _next;
	Set<T>* _head;
public:
	typedef T value_type;
};

template <typename T>
class List
{
	Node<T>* first;
	Node<T>* tail;
	
	
	friend class Set<T>;
	
public: 
	typedef Iterator<Node<T> > iterator;
	typedef T 		  value_type;
	
	List () : first(0), tail(0) {}
	~List() 
	{ 
		if (first) 
		{ 
			Node<T> *iter = first;
			while (iter != 0)
			{
				Node<T>* tmp = iter;
				iter = iter->_next;
				delete tmp;			
			}
		}
	}

	void push_back(T data)
	{
		Node<T> *newNode = new Node<T>(data);
		if (tail){
			tail->_next = newNode;
			tail = newNode;
		}
		else{
			first = tail = newNode;
		}
		newNode->_head = first;
	}; 
	
	void push_front(T data)
	{
		Node<T> *newNode = new Node<T>(data);
		if (first)
		{
			newNode->_next = first;
			first = newNode;			
		}
		else{
			first = tail = newNode;
		}
		newNode->_head = first;
	}
	
	iterator begin(){ return iterator(first); }
	iterator end(){ return iterator(0); }
	
	bool erase(iterator& _iNode) //True for success, vice versa
	{
		/* This is rather inneffecient. Maybe a better way to do this? */
		/* Even then, it's *still* more effecient than a contiguous container */
		if (_iNode.pNode == first)
		{
			first = first->_next;
			delete _iNode.pNode;
			return true;
		}
		else
		{
			for (Node<T>* iter = first; iter->_next; iter = iter->_next)
			{
				if (iter->_next == _iNode.pNode) //Find our node.
				{
					iter->_next = _iNode.pNode->_next;
					delete _iNode.pNode;
					return true;
				}
			}
		}
	
		return false;
	}
};

template <typename T>
class Set
{
	List<T> *list;
	friend class List<T>;
public:
	
	void makeSet(T data){
		list.push_back(data);
	}
	
	Set<T> findSet(Node<T> *node){
		return node->_head;
	}
};

