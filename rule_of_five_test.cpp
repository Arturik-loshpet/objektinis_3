#include "vector.h"
#include "library.h"

class TestStudent {
public:
    TestStudent(const std::string& vardas,
                const std::string& pavarde,
                const MyVector<int>& pazymiai,
                int egzaminas,
                double vidurkis,
                double mediana)
        : vardas_(vardas),
          pavarde_(pavarde),
          pazymiai_(pazymiai),
          egzaminas_(egzaminas),
          vidurkis_(vidurkis),
          mediana_(mediana) {}

    TestStudent(const TestStudent& other)
        : vardas_(other.vardas_),
          pavarde_(other.pavarde_),
          pazymiai_(other.pazymiai_),
          egzaminas_(other.egzaminas_),
          vidurkis_(other.vidurkis_),
          mediana_(other.mediana_) {}

    TestStudent(TestStudent&& other)
        : vardas_(std::move(other.vardas_)),
          pavarde_(std::move(other.pavarde_)),
          pazymiai_(std::move(other.pazymiai_)),
          egzaminas_(other.egzaminas_),
          vidurkis_(other.vidurkis_),
          mediana_(other.mediana_) {
        other.vardas_.clear();
        other.pavarde_.clear();
        other.pazymiai_.clear();
        other.egzaminas_ = 0;
        other.vidurkis_ = 0.0;
        other.mediana_ = 0.0;
    }

    TestStudent& operator=(const TestStudent& other) {
        if (this != &other) {
            vardas_ = other.vardas_;
            pavarde_ = other.pavarde_;
            pazymiai_ = other.pazymiai_;
            egzaminas_ = other.egzaminas_;
            vidurkis_ = other.vidurkis_;
            mediana_ = other.mediana_;
        }
        return *this;
    }

    TestStudent& operator=(TestStudent&& other) {
        if (this != &other) {
            vardas_ = std::move(other.vardas_);
            pavarde_ = std::move(other.pavarde_);
            pazymiai_ = std::move(other.pazymiai_);
            egzaminas_ = other.egzaminas_;
            vidurkis_ = other.vidurkis_;
            mediana_ = other.mediana_;

            other.vardas_.clear();
            other.pavarde_.clear();
            other.pazymiai_.clear();
            other.egzaminas_ = 0;
            other.vidurkis_ = 0.0;
            other.mediana_ = 0.0;
        }
        return *this;
    }

    ~TestStudent() = default;

    const std::string& vardas() const { return vardas_; }
    const std::string& pavarde() const { return pavarde_; }
    MyVector<int>& pazymiai() { return pazymiai_; }
    const MyVector<int>& pazymiai() const { return pazymiai_; }
    int egzaminas() const { return egzaminas_; }
    double vidurkis() const { return vidurkis_; }
    double mediana() const { return mediana_; }

    void setVardas(const std::string& vardas) { vardas_ = vardas; }
    void setPavarde(const std::string& pavarde) { pavarde_ = pavarde; }
    void setEgzaminas(int egzaminas) { egzaminas_ = egzaminas; }
    void setVidurkis(double vidurkis) { vidurkis_ = vidurkis; }
    void setMediana(double mediana) { mediana_ = mediana; }

private:
    std::string vardas_;
    std::string pavarde_;
    MyVector<int> pazymiai_;
    int egzaminas_ = 0;
    double vidurkis_ = 0.0;
    double mediana_ = 0.0;
};

std::ostream& operator<<(std::ostream& out, const TestStudent& studentas) {
    out << studentas.vardas() << " "
        << studentas.pavarde() << " "
        << studentas.egzaminas() << " "
        << studentas.pazymiai().size();

    for (int pazymis : studentas.pazymiai()) {
        out << " " << pazymis;
    }

    return out;
}

std::istream& operator>>(std::istream& in, TestStudent& studentas) {
    std::string vardas;
    std::string pavarde;
    int egzaminas = 0;
    int pazymiu_kiekis = 0;

    if (!(in >> vardas >> pavarde >> egzaminas >> pazymiu_kiekis)) {
        return in;
    }

    studentas.setVardas(vardas);
    studentas.setPavarde(pavarde);
    studentas.setEgzaminas(egzaminas);
    studentas.pazymiai().clear();

    for (int i = 0; i < pazymiu_kiekis; ++i) {
        int pazymis = 0;
        if (!(in >> pazymis)) {
            return in;
        }
        studentas.pazymiai().push_back(pazymis);
    }

    return in;
}

TestStudent tuscias_studentas() {
    return TestStudent("", "", MyVector<int>(), 0, 0.0, 0.0);
}

void uzpildyti_studenta(TestStudent& studentas) {
    studentas.setVardas("Jonas");
    studentas.setPavarde("Jonaitis");
    studentas.pazymiai().push_back(8);
    studentas.pazymiai().push_back(9);
    studentas.setEgzaminas(10);
    studentas.setVidurkis(9.2);
    studentas.setMediana(8.5);
}

void patikrinti_studenta(const TestStudent& studentas) {
    assert(studentas.vardas() == "Jonas");
    assert(studentas.pavarde() == "Jonaitis");
    assert(studentas.pazymiai().size() == 2);
    assert(studentas.pazymiai()[0] == 8);
    assert(studentas.pazymiai()[1] == 9);
    assert(studentas.egzaminas() == 10);
    assert(studentas.vidurkis() == 9.2);
    assert(studentas.mediana() == 8.5);
}

void patikrinti_tuscia_studenta(const TestStudent& studentas) {
    assert(studentas.vardas().empty());
    assert(studentas.pavarde().empty());
    assert(studentas.pazymiai().empty());
    assert(studentas.egzaminas() == 0);
    assert(studentas.vidurkis() == 0.0);
    assert(studentas.mediana() == 0.0);
}

void test_default_constructor() {
    MyVector<int> v;

    assert(v.empty());
    assert(v.size() == 0);
    assert(v.capacity() == 1);
}

void test_push_back_and_capacity_growth() {
    MyVector<int> v;

    v.push_back(10);
    assert(v.size() == 1);
    assert(v.capacity() == 1);
    assert(v[0] == 10);

    v.push_back(20);
    assert(v.size() == 2);
    assert(v.capacity() == 2);
    assert(v[1] == 20);

    v.push_back(30);
    assert(v.size() == 3);
    assert(v.capacity() == 4);
    assert(v[2] == 30);
}

void test_front_back_index_and_data() {
    MyVector<int> v;
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    assert(v.front() == 4);
    assert(v.back() == 6);
    assert(v.data()[1] == 5);

    v[1] = 99;
    assert(v[1] == 99);
    assert(v.data()[1] == 99);
}

void test_at_checks_bounds() {
    MyVector<int> v;
    v.push_back(7);

    assert(v.at(0) == 7);

    bool thrown = false;
    try {
        v.at(1);
    } catch (const std::out_of_range&) {
        thrown = true;
    }
    assert(thrown);
}

void test_pop_back_and_clear() {
    MyVector<int> v;
    v.push_back(1);
    v.push_back(2);
    const size_t old_capacity = v.capacity();

    v.pop_back();
    assert(v.size() == 1);
    assert(v.back() == 1);

    v.pop_back();
    v.pop_back();
    assert(v.empty());

    v.push_back(5);
    v.clear();
    assert(v.empty());
    assert(v.capacity() == old_capacity);
}

void test_copy_constructor_deep_copy() {
    MyVector<int> original;
    original.push_back(1);
    original.push_back(2);

    MyVector<int> copy(original);
    original[0] = 100;

    assert(copy.size() == 2);
    assert(copy[0] == 1);
    assert(copy[1] == 2);
}

void test_copy_assignment_deep_copy_and_self_assignment() {
    MyVector<int> original;
    original.push_back(3);
    original.push_back(4);

    MyVector<int> copy;
    copy = original;
    original[1] = 400;

    assert(copy.size() == 2);
    assert(copy[0] == 3);
    assert(copy[1] == 4);

    MyVector<int>* same = &copy;
    copy = *same;
    assert(copy.size() == 2);
    assert(copy[0] == 3);
    assert(copy[1] == 4);
}

void test_move_constructor() {
    MyVector<int> original;
    original.push_back(5);
    original.push_back(6);

    MyVector<int> moved(std::move(original));

    assert(moved.size() == 2);
    assert(moved[0] == 5);
    assert(moved[1] == 6);
    assert(original.empty());
    assert(original.capacity() == 0);
}

void test_move_assignment() {
    MyVector<int> original;
    original.push_back(7);
    original.push_back(8);

    MyVector<int> moved;
    moved.push_back(100);
    moved = std::move(original);

    assert(moved.size() == 2);
    assert(moved[0] == 7);
    assert(moved[1] == 8);
    assert(original.empty());
    assert(original.capacity() == 0);
}

void test_reserve_resize_and_shrink_to_fit() {
    MyVector<int> v;
    v.reserve(10);
    assert(v.capacity() == 10);
    assert(v.size() == 0);

    v.resize(3, 42);
    assert(v.size() == 3);
    assert(v.capacity() == 10);
    assert(v[0] == 42);
    assert(v[1] == 42);
    assert(v[2] == 42);

    v.resize(5);
    assert(v.size() == 5);
    assert(v[3] == 0);
    assert(v[4] == 0);

    v.resize(2);
    assert(v.size() == 2);

    v.shrink_to_fit();
    assert(v.capacity() == 2);
    assert(v[0] == 42);
    assert(v[1] == 42);
}

void test_iterators_and_algorithm_support() {
    MyVector<int> v;
    v.push_back(3);
    v.push_back(1);
    v.push_back(2);

    int sum = 0;
    for (int value : v) {
        sum += value;
    }
    assert(sum == 6);

    std::sort(v.begin(), v.end());
    assert(v[0] == 1);
    assert(v[1] == 2);
    assert(v[2] == 3);
}

void test_const_iterators() {
    MyVector<int> v;
    v.push_back(11);
    v.push_back(12);

    const MyVector<int>& cv = v;
    assert(*cv.begin() == 11);
    assert(*(cv.end() - 1) == 12);
    assert(*cv.cbegin() == 11);
    assert(*(cv.cend() - 1) == 12);
}

void test_erase_single_and_range() {
    MyVector<int> v;
    for (int i = 1; i <= 5; ++i) {
        v.push_back(i);
    }

    auto it = v.erase(v.begin() + 1);
    assert(*it == 3);
    assert(v.size() == 4);
    assert(v[0] == 1);
    assert(v[1] == 3);
    assert(v[2] == 4);
    assert(v[3] == 5);

    it = v.erase(v.begin() + 1, v.begin() + 3);
    assert(*it == 5);
    assert(v.size() == 2);
    assert(v[0] == 1);
    assert(v[1] == 5);
}

void test_insert_begin_middle_end() {
    MyVector<int> v;
    v.push_back(2);
    v.push_back(4);

    auto it = v.insert(v.begin(), 1);
    assert(*it == 1);
    assert(v[0] == 1);

    it = v.insert(v.begin() + 2, 3);
    assert(*it == 3);
    assert(v[2] == 3);

    it = v.insert(v.end(), 5);
    assert(*it == 5);

    assert(v.size() == 5);
    for (size_t i = 0; i < v.size(); ++i) {
        assert(v[i] == static_cast<int>(i + 1));
    }
}

void test_assign_and_swap() {
    MyVector<int> a;
    MyVector<int> b;

    a.assign(3, 9);
    assert(a.size() == 3);
    assert(a[0] == 9);
    assert(a[1] == 9);
    assert(a[2] == 9);

    b.push_back(1);
    b.push_back(2);
    a.swap(b);

    assert(a.size() == 2);
    assert(a[0] == 1);
    assert(a[1] == 2);
    assert(b.size() == 3);
    assert(b[0] == 9);
}

void test_student_rule_of_five_copy_constructor() {
    TestStudent pirmas = tuscias_studentas();
    uzpildyti_studenta(pirmas);

    TestStudent antras(pirmas);
    patikrinti_studenta(antras);

    pirmas.setVardas("Petras");
    pirmas.pazymiai().push_back(5);

    assert(antras.vardas() == "Jonas");
    assert(antras.pazymiai().size() == 2);
}

void test_student_rule_of_five_move_constructor() {
    TestStudent pirmas = tuscias_studentas();
    uzpildyti_studenta(pirmas);

    TestStudent antras(std::move(pirmas));
    patikrinti_studenta(antras);
    patikrinti_tuscia_studenta(pirmas);
}

void test_student_rule_of_five_copy_assignment() {
    TestStudent pirmas = tuscias_studentas();
    TestStudent antras = tuscias_studentas();
    uzpildyti_studenta(pirmas);

    antras = pirmas;
    patikrinti_studenta(antras);

    pirmas.setPavarde("Petraitis");
    pirmas.pazymiai().clear();

    assert(antras.pavarde() == "Jonaitis");
    assert(antras.pazymiai().size() == 2);
}

void test_student_rule_of_five_move_assignment() {
    TestStudent pirmas = tuscias_studentas();
    TestStudent antras = tuscias_studentas();
    uzpildyti_studenta(pirmas);

    antras = std::move(pirmas);
    patikrinti_studenta(antras);
    patikrinti_tuscia_studenta(pirmas);
}

void test_student_stream_output() {
    TestStudent studentas = tuscias_studentas();
    uzpildyti_studenta(studentas);
    std::ostringstream out;

    out << studentas;

    assert(out.str() == "Jonas Jonaitis 10 2 8 9");
}

void test_student_stream_input() {
    TestStudent studentas = tuscias_studentas();
    std::istringstream in("Ona Onaite 9 3 10 8 7");

    in >> studentas;

    assert(studentas.vardas() == "Ona");
    assert(studentas.pavarde() == "Onaite");
    assert(studentas.egzaminas() == 9);
    assert(studentas.pazymiai().size() == 3);
    assert(studentas.pazymiai()[0] == 10);
    assert(studentas.pazymiai()[1] == 8);
    assert(studentas.pazymiai()[2] == 7);
}

#define RUN_TEST(test_name)        \
    do {                           \
        test_name();               \
    } while (false)                 \

int main() {
    RUN_TEST(test_default_constructor);
    RUN_TEST(test_push_back_and_capacity_growth);
    RUN_TEST(test_front_back_index_and_data);
    RUN_TEST(test_at_checks_bounds);
    RUN_TEST(test_pop_back_and_clear);
    RUN_TEST(test_copy_constructor_deep_copy);
    RUN_TEST(test_copy_assignment_deep_copy_and_self_assignment);
    RUN_TEST(test_move_constructor);
    RUN_TEST(test_move_assignment);
    RUN_TEST(test_reserve_resize_and_shrink_to_fit);
    RUN_TEST(test_iterators_and_algorithm_support);
    RUN_TEST(test_const_iterators);
    RUN_TEST(test_erase_single_and_range);
    RUN_TEST(test_insert_begin_middle_end);
    RUN_TEST(test_assign_and_swap);
    RUN_TEST(test_student_rule_of_five_copy_constructor);
    RUN_TEST(test_student_rule_of_five_move_constructor);
    RUN_TEST(test_student_rule_of_five_copy_assignment);
    RUN_TEST(test_student_rule_of_five_move_assignment);
    RUN_TEST(test_student_stream_output);
    RUN_TEST(test_student_stream_input);

    std::cout << "Visi MyVector unit testai praejo." << std::endl;
    return 0;
}
