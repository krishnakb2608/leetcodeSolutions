class BrowserHistory {
private:
    stack<string> prev;
    stack<string> front;

public:
    BrowserHistory(string homepage) { prev.push(homepage); }

    void visit(string url) {
        while (!front.empty())
            front.pop();
        prev.push(url);
    }

    string back(int steps) {
        for (int i = 1; i <= steps; i++) {
            if (prev.size() > 1) {
                front.push(prev.top());
                prev.pop();
            }
        }
        return prev.top();
    }

    string forward(int steps) {
        for (int i = 1; i <= steps; i++) {
            if (front.empty())
                break;
            prev.push(front.top());
            front.pop();
        }
        return prev.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->prev(steps);
 * string param_3 = obj->forward(steps);
 */