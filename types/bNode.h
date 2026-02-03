template<typename T>
class bNode {
public:
	T* Next; // +0
	T* Prev; // +4
};
static_assert(sizeof(bNode<void>) == 0x8);

template<typename T>
class bTNode : public bNode<T> {};

template<typename T>
class bList {
public:
	bNode<T> HeadNode;

	bool empty() {
		return (void*)HeadNode == (void*)&this;
	}
};

template<typename T>
class bTList : public bList<T> {};