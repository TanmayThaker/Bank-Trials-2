//! Function to count total number of digits
/*!
    \param n is integer type
    \return count intger type
*/
int countDigits(int n)
{
    int count = 0;
    while (n != 0)
    {
        n /= 10;
        count++;
    }
    return count;
}
