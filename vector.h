#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include "library.h"
#include <stdexcept>

/**
 * @brief Paprastas dinaminio masyvo konteineris, panasus i std::vector.
 * @tparam T Saugomu elementu tipas.
 */
template <typename T>
class MyVector{
    private:
        size_t size_;
        size_t capacity_;
        T* data_;
        /**
         * @brief Padidina konteinerio talpa dvigubai.
         */
        void grow(){ //padidina capacity_ vektoriui
            if(capacity_ == 0) capacity_ = 1;
            else capacity_ = capacity_ * 2;
            T * newData = new T[capacity_];
            for(size_t i=0; i<size_; i++){
                newData[i] = data_[i];
            }
            delete[] data_;
            data_ = newData;
        }
    public:

        /**
         * @brief Konteineryje saugomu elementu tipas.
         */
        using value_type = T;

        /*
        ---------------------------------------------------
        Konstruktoriai
        */
        /**
         * @brief Sukuria tuscia konteineri su pradine talpa 1.
         */
        MyVector(): //vektoriaus konstruktorius
        size_(0),
        capacity_(1),
        data_(new T[capacity_]){}

        /**
         * @brief Kopijavimo konstruktorius.
         * @param other Konteineris, is kurio kopijuojami duomenys.
         */
        MyVector(const MyVector& other): //copy konstruktorius
            size_(other.size_),
            capacity_(other.capacity_),
            data_(new T[other.capacity_]){
                for(size_t i =0; i< size_; i++){
                    data_[i] = other.data_[i];
                }
            }

        /**
         * @brief Perkelimo konstruktorius.
         * @param other Konteineris, kurio duomenys perkeliami.
         */
        MyVector(MyVector&& other): // move konstruktorius
            size_(other.size_),
            capacity_(other.capacity_),
            data_(other.data_)
            {
                other.size_ = 0;
                other.capacity_ = 0;
                other.data_ = nullptr;
            }

        /*
        ---------------------------------------------------
        Operatoriai
        */

        /**
         * @brief Grazina elemento nuoroda pagal indeksa be ribu tikrinimo.
         * @param index Elemento indeksas.
         * @return Elemento nuoroda.
         */
        T & operator[](size_t index){ //grazina vektoriaus reiksme duotam indexe
            return data_[index];
        }

        /**
         * @brief Kopijavimo priskyrimo operatorius.
         * @param other Konteineris, is kurio kopijuojami duomenys.
         * @return Nuoroda i si konteineri.
         */
        MyVector& operator=(const MyVector& other){ // lygu operatorius :(
            if(this != &other){
                delete[] data_;
                size_ = other.size_;
                capacity_ = other.capacity_;
                data_ = new T[other.capacity_];{
                    for(size_t i =0; i< size_; i++){
                        data_[i] = other.data_[i];
                    }
                }
            }
            return *this;
        }

        /**
         * @brief Perkelimo priskyrimo operatorius.
         * @param other Konteineris, kurio duomenys perkeliami.
         * @return Nuoroda i si konteineri.
         */
        MyVector& operator=(MyVector&& other) { //move assignment operatorius
            if (this != &other) {
                delete[] data_;

                size_ = other.size_;
                capacity_ = other.capacity_;
                data_ = other.data_;

                other.size_ = 0;
                other.capacity_ = 0;
                other.data_ = nullptr;
            }

        return *this;
        }

        /**
         * @brief Grazina elemento konstancia nuoroda pagal indeksa be ribu tikrinimo.
         * @param index Elemento indeksas.
         * @return Konstanti elemento nuoroda.
         */
        const T& operator[](size_t index) const{
            return data_[index];
        }

        /*
        ---------------------------------------------------
        Funkcijos
        */

        /**
         * @brief Prideda elementa i konteinerio gala.
         * @param val Pridedama reiksme.
         */
        void push_back(const T& val){ //Iraso nauja kintamaji i vektorio funkcija
            if (size_ == capacity_) grow();
            data_[size_] = val;
            size_++;
        }

        /**
         * @brief Pasalina paskutini elementa, jei konteineris netuscias.
         */
        void pop_back(){ //istrina nari vektoriaus gale
            if(size_ > 0) size_--;
        }

        /**
         * @brief Patikrina, ar konteineris tuscias.
         * @return true, jei elementu nera.
         */
        bool empty(){ //patikrina ar vektorius tuscias
            return size_ == 0;
        }

        /**
         * @brief Patikrina, ar konteineris tuscias.
         * @return true, jei elementu nera.
         */
        bool empty() const{ //const versija sios funkcijos
            return size_ == 0;
        }

        /**
         * @brief Grazina elementu kieki.
         * @return Elementu kiekis.
         */
        size_t size(){ //grazina vektoriaus dydi
            return size_;
        }

        /**
         * @brief Grazina elementu kieki.
         * @return Elementu kiekis.
         */
        size_t size() const{ //konstanta
            return size_;
        }

        /**
         * @brief Grazina dabartine konteinerio talpa.
         * @return Talpa.
         */
        size_t capacity() { //grazina vektoriaus capacity_
            return capacity_;
        }

        /**
         * @brief Grazina dabartine konteinerio talpa.
         * @return Talpa.
         */
         size_t capacity() const{
            return capacity_;
         }

        /**
         * @brief Pasalina visus elementus, bet talpos nemazina.
         */
        void clear(){ //isvalo vektoriu
            size_ = 0;
        }

        /**
         * @brief Sumazina talpa iki dabartinio elementu kiekio.
         */
        void shrink_to_fit(){ //sumazina vektoriaus capacity_ iki uzpildyto vektoriaus dydzio
            if(capacity_ > size_){
                T* newData = new T[size_];

                for(size_t i =0; i<size_; i++){
                    newData[i] = data_[i];
                }

                delete[] data_;
                data_ = newData;
                capacity_ = size_;
            }
        }

        /**
         * @brief Grazina iteratoriu i pirma elementa.
         * @return Rodykle i pirma elementa.
         */
        T* begin() {
            return data_;
        }

        /**
         * @brief Grazina iteratoriu uz paskutinio elemento.
         * @return Rodykle uz paskutinio elemento.
         */
        T* end() {
            return data_ + size_;
        }

        /**
         * @brief Grazina konstantu iteratoriu i pirma elementa.
         * @return Konstanti rodykle i pirma elementa.
         */
        const T* begin() const {
            return data_;
        }

        /**
         * @brief Grazina konstantu iteratoriu uz paskutinio elemento.
         * @return Konstanti rodykle uz paskutinio elemento.
         */
        const T* end() const {
            return data_ + size_;
        }

        /**
         * @brief Grazina paskutinio elemento nuoroda.
         * @return Paskutinio elemento nuoroda.
         */
        T& back(){
            return data_[size_ - 1];
        }

        /**
         * @brief Grazina paskutinio elemento konstancia nuoroda.
         * @return Konstanti paskutinio elemento nuoroda.
         */
        const T& back() const{
            return data_[size_ - 1];
        }

        /**
         * @brief Grazina pirmo elemento nuoroda.
         * @return Pirmo elemento nuoroda.
         */
        T& front(){
            return data_[0];
        }

        /**
         * @brief Grazina pirmo elemento konstancia nuoroda.
         * @return Konstanti pirmo elemento nuoroda.
         */
        const T& front() const{
            return data_[0];
        }

        /**
         * @brief Pasalina elementu intervala.
         * @param first Pirmas salinamas elementas.
         * @param last Iteratorius uz paskutinio salinamo elemento.
         * @return Iteratorius i vieta, kur buvo pasalintas intervalas.
         */
        T* erase(T* first, T* last){
            std::move(last, end(), first);
            size_ -= last - first;
            return first;
        }

        /**
         * @brief Pasalina viena elementa.
         * @param pos Salinamo elemento iteratorius.
         * @return Iteratorius i vieta, kur buvo pasalintas elementas.
         */
        T* erase(T* pos) {
            return erase(pos, pos + 1);
        }

        /**
         * @brief Grazina elemento nuoroda su ribu tikrinimu.
         * @param index Elemento indeksas.
         * @return Elemento nuoroda.
         * @throws std::out_of_range Jei indeksas uz konteinerio ribu.
         */
        T& at(size_t index){ //patikrina vektoriaus ribas
            if(size_ <= index){
                throw std::out_of_range("MyVector index out of range");
            }
            return data_[index];
        }

        /**
         * @brief Grazina konstancia elemento nuoroda su ribu tikrinimu.
         * @param index Elemento indeksas.
         * @return Konstanti elemento nuoroda.
         * @throws std::out_of_range Jei indeksas uz konteinerio ribu.
         */
        const T& at(size_t index) const {
            if (index >= size_) {
                throw std::out_of_range("MyVector index out of range");
            }

            return data_[index];
        }

        /**
         * @brief Padidina konteinerio talpa, jei nauja talpa didesne uz esama.
         * @param newCapacity Nauja pageidaujama talpa.
         */
        void reserve(size_t newCapacity){ //pakeisti vektoriaus capacity
            if(newCapacity <= capacity_){
                return;
            }

            T* newData = new T[newCapacity];
            for(size_t i=0; i<size_; i++){
                newData[i] = data_[i];
            }

            delete[] data_;
            data_ = newData;
            capacity_ = newCapacity;
        }

        /**
         * @brief Pakeicia konteinerio dydi.
         * @param newSize Naujas elementu kiekis.
         */
        void resize(size_t newSize){  //resizina vektoriu iki tam tikro dydzio
            if(newSize > capacity_) reserve(newSize);

            for(size_t i=size_; i<newSize; i++){
                data_[i] = T();
            }

            size_ = newSize;
        }

        /**
         * @brief Pakeicia konteinerio dydi ir naujus elementus uzpildo reiksme.
         * @param newSize Naujas elementu kiekis.
         * @param value Reiksme naujiems elementams.
         */
        void resize(size_t newSize, const T& value) { //resizina vektoriu iki naudotujui reikalingo dydzio ir tuscius laukus uzpildo duotom reiksmes
            if (newSize > capacity_) reserve(newSize);

            for (size_t i = size_; i < newSize; i++) {
                data_[i] = value;
            }

            size_ = newSize;
        }

        /**
         * @brief Grazina rodykle i vidini masyva.
         * @return Rodykle i duomenu pradzia.
         */
        T* data(){ //vektoriaus pradzios adresas
            return data_;
        }

        /**
         * @brief Grazina konstantu iteratoriu i pradzia.
         * @return Konstanti rodykle i duomenu pradzia.
         */
        T* cbegin() const{ //vektoriaus pradzios adreas
            return data_;
        }

        /**
         * @brief Grazina konstantu iteratoriu uz paskutinio elemento.
         * @return Konstanti rodykle uz paskutinio elemento.
         */
        const T* cend() const { //bektoriaus pabaigos adresas
            return data_ + size_;
        }

        /**
         * @brief Apkeicia dvieju konteineriu duomenis.
         * @param other Kitas konteineris.
         */
        void swap(MyVector& other) { //apkeicia vektorius nariais, vietoj move ar copy
            std::swap(size_, other.size_);
            std::swap(capacity_, other.capacity_);
            std::swap(data_, other.data_);
        }

        /**
         * @brief Uzpildo konteineri nurodytu kiekiu vienodu reiksmiu.
         * @param count Elementu kiekis.
         * @param value Priskiriama reiksme.
         */
        void assign(size_t count, const T& value){ //priskiria vektoriui reiksme
            if(count > capacity_) reserve(count);
            for(size_t i = 0; i<count; i++){
                data_[i] = value;
            }
            size_ = count;
        }

        /**
         * @brief Iterpia elementa nurodytoje vietoje.
         * @param pos Iterpimo vieta.
         * @param value Iterpiama reiksme.
         * @return Iteratorius i iterpta elementa.
         */
        T* insert(T* pos, const T& value) { //ideda nauja reiksme i nauja indexa vektoriuje
            size_t index = pos - begin();

            if (size_ == capacity_) grow();

            for (size_t i = size_; i > index; i--) {
                data_[i] = data_[i - 1];
            }

            data_[index] = value;
            size_++;

            return data_ + index;
        }

        /**
         * @brief Atlaisvina konteinerio naudojama atminti.
         */
        ~MyVector(){ //destruktorius
            delete[] data_;
            size_ = 0;
            capacity_ = 0;
        }
	};

/**
 * @brief Pamatuoja, kiek laiko uztrunka uzpildyti konteineri skaiciais.
 * @tparam Container Konteinerio tipas.
 * @param vec Pildomas konteineris.
 * @param sk Kiek elementu prideti.
 */
template <typename Container>
void pildymas(Container& vec, int sk){
    const auto pradzia = std::chrono::high_resolution_clock::now();
    for(int i=0; i<sk; i++){
        vec.push_back(i);
    }
    const auto pabaiga = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double, std::milli> trukme = pabaiga - pradzia;
    std::cout << trukme.count() << std::endl;
}

#endif
