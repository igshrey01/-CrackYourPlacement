class MyStack {
public:
queue<int> q;
MyStack() {

}

void push(int x) {
    queue<int>temp;
    temp.push(x);
    while(!q.empty()){
        temp.push(q.front());
        q.pop();
    }
    q=temp;
}

int pop() {
    int val = q.front();
    q.pop();
    return val;
}

int top() {
    return q.front();
}

bool empty() {
    return q.empty();
}
};