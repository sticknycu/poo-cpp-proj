# UtilityIT Template
![C/C++ CI](https://github.com/nicugnm/poo-cpp-proj/workflows/C/C++%20CI/badge.svg?branch=main)
### Tema 0

- [X] nume proiect (îl puteți schimba ulterior)
- [X] Scurtă descriere a temei alese, ce v-ați propus să implementați
- [X] actualizat `.gitignore` dacă nu sunt ignorate fișierele (binare) generate de editor/IDE; puteți folosi https://gitignore.io

## Tema 1 - UtilityIT

#### Deadlines semestrul 1
- săptămâna 3 (23 octombrie): stabilirea claselor și implementarea parțială a acestora
- **săptămâna 4 (30 octombrie): tema 1 gata**
- săptămâna 5 (6 noiembrie): (eventuale) modificări în urma feedback-ului

#### Cerințe
- [X] definirea a minim 3 clase
    - [X] Comment
    - [X] Event
    - [X] Group
    - [X] Post
    - [X] Profile
    - [X] Reaction
    - [X] ReactionEnum
    - [X] Rule
    - [X] User
    - [X] Utils
- [X] constructori de inițializare
- [X] constructor de copiere sau cc (pt minim o clasă)
- [X] `operator=` sau op= (pt minim o clasă, aceeași unde s-a făcut cc și destructor)
- [X] destructor (pt minim o clasă, aceeași unde s-a făcut cc și op=)
- [X] `operator<<` pt toate clasele
- [X] cât mai multe `const`
- [X] implementarea a minim 2 funcții publice pentru funcționalități specifice temei alese (nu se iau în considerare citiri/afișări/getteri/setteri)
    - [X] handleRegister
    - [X] registerUser
    - [X] loginUser
    - [X] navigatePlatform
- [X] scenariu de utilizare a claselor definite: apelarea din `main` a tuturor funcțiilor _publice_ definite (nu generați constructori/getteri/setteri dacă nu aveți nevoie de ei); apelarea se va face direct sau indirect - adică din `main` se pot apela funcții care construiesc obiecte cu clasele definite și folosesc aceste obiecte
- [X] după ce e gata prima temă, tag de `git`: de exemplu `v0.1`
- [X] GitHub Actions sau alt serviciu de CI (Continuous Integration) - exemplu [aici](https://github.com/mcmarius/demo-poo/blob/master/.github/workflows/cmake.yml) (a se vedea și `CMakeLists.txt` din același repo pt compiler flags)

## Tema 2

#### Deadlines semestrul 1
- săptămâna 7 (20 noiembrie): progres parțial
- **săptămâna 8 (27 noiembrie): tema 2 gata**
- săptămâna 9 (4 decembrie): (eventuale) modificări în urma feedback-ului

#### Cerințe
- [X] separarea codului din clase în `.h` (sau `.hpp`) și `.cpp`
- [X] moșteniri
  - [X] funcții virtuale (pure)
  - [X] apelarea constructorului din clasa de bază
  - [X] smart pointers / pointeri normali și verificat să nu fie memory leaks
- [X] excepții
  - [X] predefinite
  - [X] ierarhie proprie (cu baza `std::exception` sau derivată din `std::exception`)
  - [X] utilizare cu sens: de exemplu, `throw` în constructor, `try`/`catch` în `main`
- [X] funcții și atribute `static`
- [X] STL
- [X] cât mai multe `const`
- [X] la fel ca mai sus, apelarea tuturor funcțiilor publice din `main`
- [X] încă un tag de `git`: de exemplu `v0.2`

## Tema 3

#### Deadlines semestrul 1
- săptămâna 10 (11 decembrie): progres parțial
- **săptămâna 11 (18 decembrie): tema 3 gata**
- săptămâna 12 (22-29 decembrie): (eventuale) modificări în urma feedback-ului

#### Cerințe
- [X] 2 design patterns
  - [X] Builder
  - [X] Singleton
- [X] funcții și clase șablon (`template`)
- [X] un ultim (?) tag de `git`: de exemplu `v0.3` sau `v1.0`

## Description

UtilityIT este o mini-plaforma de socializare.
Aceasta simuleaza actiuni precum adaugarea de comentarii, adaugarea de reactii, crearea de post-uri noi, crearea de conturi noi.
Toate informatiile sunt salvate in fisierele specifice .txt, de unde sunt manipulate datele.

Mi-am propus sa implementez clasele Comment si Reaction specifice unui post.
Evidentierea unui post se face prin clasa Post.
Fiecare utilizator este definit prin clasa User, iar fiecare utilizator are un profil care se poate identifica prin clasa Profile.
Fiecare profil este identificat in functie de id-ul gasit in clasa User.
Ca si utilizator poti intra in grupuri, un grup fiind evidentiat prin clasa Group, iar fiecare grup poate avea niste reguli, fiecare regula fiind evidentiata prin clasa Rule.
Am implementat si o clasa Utils prin care se folosesc functii statice, in general, care nu au legatura cu celelalte clase, precum split-ul unui string.