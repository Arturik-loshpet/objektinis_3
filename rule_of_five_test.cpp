#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "funkcijos.h"
#include "doctest.h"
#include "library.h"

VectorStudent sukurti_studenta() {
    VectorStudent studentas;
    studentas.setVardas("Jonas");
    studentas.setPavarde("Jonaitis");
    studentas.pazymiai() = {8, 9};
    studentas.setEgzaminas(10);
    studentas.setVidurkis(9.2);
    studentas.setMediana(8.5);
    return studentas;
}

TEST_CASE("Rule of five testas"){
    VectorStudent zmogus = sukurti_studenta();
    SUBCASE("Konstruktorius"){
        CHECK(zmogus.vardas() == "Jonas");
        CHECK(zmogus.pavarde() == "Jonaitis");
        CHECK(zmogus.pazymiai() == std::vector<int>{8, 9});
        CHECK(zmogus.egzaminas() == 10);
        CHECK(zmogus.vidurkis() == doctest::Approx(9.2));
        CHECK(zmogus.mediana() == doctest::Approx(8.5));
    }
    SUBCASE("Copy"){
        VectorStudent kopija(zmogus);
        CHECK(kopija.vardas() == "Jonas");
        CHECK(kopija.pavarde() == "Jonaitis");
        CHECK(kopija.pazymiai() == std::vector<int>{8, 9});
        CHECK(kopija.egzaminas() == 10);
        CHECK(kopija.vidurkis() == doctest::Approx(9.2));
        CHECK(kopija.mediana() == doctest::Approx(8.5));
    }
    SUBCASE("Move konstruktorius"){
        VectorStudent kopija(std::move(zmogus));
        CHECK(kopija.vardas() == "Jonas");
        CHECK(kopija.pavarde() == "Jonaitis");
        CHECK(kopija.pazymiai() == std::vector<int>{8, 9});
        CHECK(kopija.egzaminas() == 10);
        CHECK(kopija.vidurkis() == doctest::Approx(9.2));
        CHECK(kopija.mediana() == doctest::Approx(8.5));
        //destruktoriaus patikra
        CHECK(zmogus.vardas().empty());
        CHECK(zmogus.pavarde().empty());
        CHECK(zmogus.pazymiai().empty());
        CHECK(zmogus.egzaminas() == 0);
        CHECK(zmogus.vidurkis() == 0.0);
        CHECK(zmogus.mediana() == 0.0);
    }
    SUBCASE("= operatorius"){
        VectorStudent dummy;
        dummy.setVardas("A");
        dummy.setPavarde("b");
        dummy.pazymiai() = {1, 2};
        dummy.setEgzaminas(10);
        dummy.setVidurkis(4.2);
        dummy.setMediana(4.3);
        dummy = zmogus;
        CHECK(dummy.vardas() == "Jonas");
        CHECK(dummy.pavarde() == "Jonaitis");
        CHECK(dummy.pazymiai() == std::vector<int>{8, 9});
        CHECK(dummy.egzaminas() == 10);
        CHECK(dummy.vidurkis() == doctest::Approx(9.2));
        CHECK(dummy.mediana() == doctest::Approx(8.5));
    }
    SUBCASE("move operatorius"){
        VectorStudent dummy;
        dummy.setVardas("A");
        dummy.setPavarde("b");
        dummy.pazymiai() = {1, 2};
        dummy.setEgzaminas(10);
        dummy.setVidurkis(4.2);
        dummy.setMediana(4.3);
        dummy = std::move(zmogus);
        CHECK(dummy.vardas() == "Jonas");
        CHECK(dummy.pavarde() == "Jonaitis");
        CHECK(dummy.pazymiai() == std::vector<int>{8, 9});
        CHECK(dummy.egzaminas() == 10);
        CHECK(dummy.vidurkis() == doctest::Approx(9.2));
        CHECK(dummy.mediana() == doctest::Approx(8.5));
        //destruktoriaus patikra
        CHECK(zmogus.vardas().empty());
        CHECK(zmogus.pavarde().empty());
        CHECK(zmogus.pazymiai().empty());
        CHECK(zmogus.egzaminas() == 0);
        CHECK(zmogus.vidurkis() == 0.0);
        CHECK(zmogus.mediana() == 0.0);
    }
}

TEST_CASE("Studentas paveldi Zmogus funkcionaluma"){
    VectorStudent studentas = sukurti_studenta();
    Zmogus& zmogus = studentas;

    CHECK(zmogus.vardas() == "Jonas");
    CHECK(zmogus.pavarde() == "Jonaitis");
    CHECK(zmogus.tipas() == "Studentas");

    zmogus.setVardas("Petras");
    zmogus.setPavarde("Petraitis");

    CHECK(studentas.vardas() == "Petras");
    CHECK(studentas.pavarde() == "Petraitis");
    CHECK(studentas.egzaminas() == 10);
    CHECK(studentas.pazymiai() == std::vector<int>{8, 9});
}

TEST_CASE("Skaiciavimai"){
    VectorStudent studentas;
    studentas.setVardas("A");
    studentas.setPavarde("b");
    studentas.pazymiai() = {1, 2, 3, 4};
    studentas.setEgzaminas(10);

    VectorContainer studentai = {studentas};
    SUBCASE("Vidurkis"){
        vidurkis(studentai);
        CHECK(studentai[0].vidurkis() == doctest::Approx(7));
    }
    SUBCASE("Mediana"){
        mediana(studentai);
        CHECK(studentai[0].mediana() == doctest::Approx(2.5));
    }
}

//Vektoriaus testavimas prasideda

TEST_CASE("Vektoriaus testavimas"){
    MyVector<int> vector;
    SUBCASE("Skaicius idedamas"){
        vector.push_back(1);
        CHECK(vector[0] == 1);
        CHECK(vector.size() == 1);
        CHECK(vector.capacity() == 1);
    }
    SUBCASE("Size yra accurate"){
        for(int i=0; i<5; i++){
            vector.push_back(i);
        }
        CHECK(vector.size() == 5);
    }
    SUBCASE("Capacity dideja"){
        for(int i=0; i<5; i++){
            vector.push_back(i);
        }
        CHECK(vector.capacity() == 8);
    }
    SUBCASE("reserve patikra"){
        vector.push_back(1);
        vector.reserve(10);
        CHECK(vector.capacity() == 10);
    }
    SUBCASE("Resize patikra"){
        vector.push_back(1);
        vector.resize(10);
        CHECK(vector.size() == 10);
    }
    SUBCASE("Cope konstruktorius"){
        MyVector<int> vector2;
        for(int i=0; i<5; i++){
            vector.push_back(i);
        }
        vector2 = vector;
        CHECK(vector[3] == vector2[3]);
        CHECK(vector.size() == vector2.size());
        CHECK(vector2.capacity() == vector.capacity());
    }
    SUBCASE("Move konstruktorius"){
        for(int i=0; i<5; i++){
            vector.push_back(i);
        }
        MyVector <int> vector2(std::move(vector));
        CHECK(vector2[3] == 3);
        CHECK(vector2.size() == 5);
        CHECK(vector2.capacity() == 8);
        CHECK(vector.empty() == true);
        CHECK(vector.size() == 0);
        CHECK(vector.capacity() == 0);
    }
}

