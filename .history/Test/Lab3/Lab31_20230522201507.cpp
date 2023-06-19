#include <iostream>
#include <queue>

int josephusProblem(int n, int k)
{
    std::queue<int> survivors;

    // initialize the queue
    for (int i = 1; i <= n; ++i)
        survivors.push(i);

    while (survivors.size() > 1)
    {
        // pop k-1 people and push them back to the queue
        for (int count = 0; count < k - 1; ++count)
        {
            survivors.push(survivors.front());
            survivors.pop();
        }

        // the k-th person is removed
        survivors.pop();
    }

    return survivors.front();
}

int main()
{
    int n = 7, k = 3;
    std::cout << "The chosen place is " << josephusProblem(n, k) << std::endl;
    system("pause");
    return 0;
}
