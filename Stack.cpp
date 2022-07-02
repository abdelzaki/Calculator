#include "Stack.h"
#include <deque>

const string StackChanged = "stackChanged";
const string StackError = "error";

class Stack::StackImpl 
{
public:
	explicit StackImpl(Stack&);
	double pop(bool suppressChangeEvent );
	void push(double, bool suppressChangeEvent);
	void swapTop();
	size_t getSize() { return m_stack.size(); }
	std::vector<double> getElements(int);
	void clear();
	double top() const;
	~ StackImpl();
private:
	 Stack& m_parent;
	std::deque<double>m_stack;
};

// stackImpl 
Stack::StackImpl::StackImpl(Stack& stack) : m_parent{stack}
{
	m_parent.privateElement;
	std::cout << "StackImpl is created "<< m_parent.privateElement << " \n";
	m_parent.regiserEvent(StackChanged);
	m_parent.regiserEvent(StackError);
}

double Stack::StackImpl::pop(bool suppressChangeEvent)
{
	if (m_stack.size() == 0)
		throw std::exception("stack is empty");
	auto lastElement = m_stack.back();
	m_stack.pop_back();
	m_parent.raise(StackChanged, nullptr);
	return lastElement;
}

void Stack::StackImpl::push(double element, bool suppressChangeEvent)
{
	m_stack.push_back(element);
	if (!suppressChangeEvent)
		m_parent.raise(StackChanged, nullptr);
}

void Stack::StackImpl::swapTop()
{
	if (m_stack.size() < 2)
		throw std::exception("the stack has less than two elements");
	auto last = m_stack.back();
	m_stack.pop_back();
	auto beforeLast = m_stack.back();
	m_stack.pop_back();
	m_stack.push_back(last);
	m_stack.push_back(beforeLast);
	m_parent.raise(StackChanged, nullptr);
}

std::vector<double> Stack::StackImpl::getElements(int numberOfElements)
{
	std::vector<double> vec;
	vec.insert(vec.end(), m_stack.crbegin(), m_stack.crbegin() + numberOfElements);
	return vec;
}

void Stack::StackImpl::clear()
{
	m_stack.clear();
	m_parent.raise(StackChanged, nullptr);
}

double Stack::StackImpl::top() const
{
	if (m_stack.size() == 0)
		throw std::exception("stack is empty");
	return m_stack.back();
}

Stack::StackImpl::~StackImpl()
{
	std::cout << "StackImpl is deleted \n";
}

/* Public interface */
Stack& Stack::instance()
{
	static Stack instance;
	return instance;
}

double Stack::pop(bool suppressChangeEvent)
{	
	return pimpl->pop(suppressChangeEvent);
}

void Stack::push(double element, bool suppressChangeEvent)
{
	pimpl->push(element, suppressChangeEvent);
}

void Stack::swapTop()
{
	pimpl->swapTop();
}

size_t Stack::size() const
{
	return pimpl->getSize();
}

std::vector<double> Stack::getElements(int number) const
{
	return pimpl->getElements(number);
}

Stack::Stack()
{
	std::cout << "unique instance of the stack is created \n";
	pimpl = std::make_unique<StackImpl>(*this);
}

Stack::~Stack()
{
	std::cout << "Stack is deleted \n";
}