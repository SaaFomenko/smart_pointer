#include <iostream>
#include <vector>
#include <memory>


std::string vec_to_str(std::vector<double>& vec, const std::string div)
{
    std::string str = "";
    bool isStart = true;

    for (double elem : vec)
    {
        if (isStart)
        {
            str += std::to_string(elem);
            isStart = false;
        }
        else
        {
            str += div + std::to_string(elem);
        }
    }

    return str;
}

class tridiagonal_matrix
{
public:
    std::vector<double> m_down;
    std::vector<double> m_upper;
    std::vector<double> m_middle;
    tridiagonal_matrix(
        const std::vector<double>& down,
        const std::vector<double>& upper,
        const std::vector<double>& middle) :
        m_down{ down }, m_upper{ upper }, m_middle{ middle }
    {};
    ~tridiagonal_matrix() { std::cout << "destructor called\n"; }

    // clone()
    std::unique_ptr<tridiagonal_matrix> clone()
    {
        return std::make_unique<tridiagonal_matrix>(m_down, m_upper, m_middle);
    }

    const std::string to_str(const std::string col_div=", ", const std::string row_div="\n")
    {
        std::string str = "";

        str = vec_to_str(m_upper, col_div) + row_div;
        str += vec_to_str(m_middle, col_div) + row_div;
        str += vec_to_str(m_down, col_div) + row_div;
        const std::string text = str;

        return text;
    }
};

int main()
{
    auto down = std::vector<double>{ -4.0, 5.0 };
    auto upper = std::vector<double>{ 14.0, 8.0 };
    auto middle = std::vector<double>{ 3.0, 1.0, 7.0 };
    auto matrix = std::make_unique<tridiagonal_matrix>(
        down,
        upper,
        middle
    );

    auto matrix_clone = matrix->clone();
    std::cout << matrix_clone->to_str();

    return 0;
}