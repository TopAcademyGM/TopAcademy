
class Rect;

int main(int argc, char const *argv[])
{
    Rect empty;
    Rect a(10, 15);
    Rect b(a);

    a = Rect(5,5);
    cout << "A:\t" << a << "\n";
    cout << "A + B:\t" << a + b << "\n";
    cout << "A - B:\t" << a + b << "\n";
    if (a >= b) {
        std::cout << "A >= B";
    }
    return 0;
}
