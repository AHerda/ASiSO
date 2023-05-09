import matplotlib.pyplot as plt
import numpy as np

dane_str = []
dane = []

file = open("select.txt")
dane_str = file.read().split()
file.close()

for i in dane_str:
    dane.append(int(i))

select_n = dane[::3]
select_c = dane[1::3]
select_s = dane[2::3]

avg_select_n = []
avg_select_c = []
avg_select_s = []

for i in range(100):
    avg_select_n.append(select_n[i * 100])
    avg_select_c.append(0)
    avg_select_s.append(0)
    for j in range(100):
        avg_select_c[i] += select_c[i * 100 + j]
        avg_select_s[i] += select_s[i * 100 + j]
    avg_select_c[i] /= 100
    avg_select_s[i] /= 100

dane_str = []
dane = []

file = open("rand_select.txt")
dane_str = file.read().split()
file.close()

for i in dane_str:
    dane.append(int(i))

rand_select_n = dane[::3]
rand_select_c = dane[1::3]
rand_select_s = dane[2::3]

avg_rand_select_n = []
avg_rand_select_c = []
avg_rand_select_s = []

for i in range(100):
    avg_rand_select_n.append(rand_select_n[i * 100])
    avg_rand_select_c.append(0)
    avg_rand_select_s.append(0)
    for j in range(100):
        avg_rand_select_c[i] += rand_select_c[i * 100 + j]
        avg_rand_select_s[i] += rand_select_s[i * 100 + j]
    avg_rand_select_c[i] /= 100
    avg_rand_select_s[i] /= 100

dane_str = []
dane = []

file = open("select_5_3.txt")
dane_str = file.read().split()
file.close()

for i in dane_str:
    dane.append(int(i))

select_5_3_n = dane[::4]
select_5_3_c = dane[1::4]
select_5_3_s = dane[2::4]
select_5_3_t = dane[3::4]

avg_select_5_3_n = []
avg_select_5_3_c = []
avg_select_5_3_s = []
avg_select_5_3_t = []

for i in range(100):
    avg_select_5_3_n.append(select_5_3_n[i * 100])
    avg_select_5_3_c.append(0)
    avg_select_5_3_s.append(0)
    avg_select_5_3_t.append(0)
    for j in range(100):
        avg_select_5_3_c[i] += select_5_3_c[i * 100 + j]
        avg_select_5_3_s[i] += select_5_3_s[i * 100 + j]
        avg_select_5_3_t[i] += select_5_3_t[i * 100 + j]
    avg_select_5_3_c[i] /= 100
    avg_select_5_3_s[i] /= 100
    avg_select_5_3_t[i] /= 100

dane_str = []
dane = []

file = open("select_5_5.txt")
dane_str = file.read().split()
file.close()

for i in dane_str:
    dane.append(int(i))

select_5_5_n = dane[::4]
select_5_5_c = dane[1::4]
select_5_5_s = dane[2::4]
select_5_5_t = dane[3::4]

avg_select_5_5_n = []
avg_select_5_5_c = []
avg_select_5_5_s = []
avg_select_5_5_t = []

for i in range(100):
    avg_select_5_5_n.append(select_5_5_n[i * 100])
    avg_select_5_5_c.append(0)
    avg_select_5_5_s.append(0)
    avg_select_5_5_t.append(0)
    for j in range(100):
        avg_select_5_5_c[i] += select_5_5_c[i * 100 + j]
        avg_select_5_5_s[i] += select_5_5_s[i * 100 + j]
        avg_select_5_5_t[i] += select_5_5_t[i * 100 + j]
    avg_select_5_5_c[i] /= 100
    avg_select_5_5_s[i] /= 100
    avg_select_5_5_t[i] /= 100

dane_str = []
dane = []

file = open("select_5_7.txt")
dane_str = file.read().split()
file.close()

for i in dane_str:
    dane.append(int(i))

select_5_7_n = dane[::4]
select_5_7_c = dane[1::4]
select_5_7_s = dane[2::4]
select_5_7_t = dane[3::4]

avg_select_5_7_n = []
avg_select_5_7_c = []
avg_select_5_7_s = []
avg_select_5_7_t = []

for i in range(100):
    avg_select_5_7_n.append(select_5_7_n[i * 100])
    avg_select_5_7_c.append(0)
    avg_select_5_7_s.append(0)
    avg_select_5_7_t.append(0)
    for j in range(100):
        avg_select_5_7_c[i] += select_5_7_c[i * 100 + j]
        avg_select_5_7_s[i] += select_5_7_s[i * 100 + j]
        avg_select_5_7_t[i] += select_5_7_t[i * 100 + j]
    avg_select_5_7_c[i] /= 100
    avg_select_5_7_s[i] /= 100
    avg_select_5_7_t[i] /= 100

dane_str = []
dane = []

file = open("select_5_9.txt")
dane_str = file.read().split()
file.close()

for i in dane_str:
    dane.append(int(i))

select_5_9_n = dane[::4]
select_5_9_c = dane[1::4]
select_5_9_s = dane[2::4]
select_5_9_t = dane[3::4]

avg_select_5_9_n = []
avg_select_5_9_c = []
avg_select_5_9_s = []
avg_select_5_9_t = []

for i in range(100):
    avg_select_5_9_n.append(select_5_9_n[i * 100])
    avg_select_5_9_c.append(0)
    avg_select_5_9_s.append(0)
    avg_select_5_9_t.append(0)
    for j in range(100):
        avg_select_5_9_c[i] += select_5_9_c[i * 100 + j]
        avg_select_5_9_s[i] += select_5_9_s[i * 100 + j]
        avg_select_5_9_t[i] += select_5_9_t[i * 100 + j]
    avg_select_5_9_c[i] /= 100
    avg_select_5_9_s[i] /= 100
    avg_select_5_9_t[i] /= 100

dane_str = []
dane = []

file = open("bin_search_lewo.txt")
dane_str = file.read().split()
file.close()

for i in dane_str:
    dane.append(int(i))

bin_search_lewo_n = dane[::3]
bin_search_lewo_c = dane[1::3]
bin_search_lewo_t = dane[2::3]

avg_bin_search_lewo_n = []
avg_bin_search_lewo_c = []
avg_bin_search_lewo_t = []

for i in range(100):
    avg_bin_search_lewo_n.append(bin_search_lewo_n[i * 100])
    avg_bin_search_lewo_c.append(0)
    avg_bin_search_lewo_t.append(0)
    for j in range(100):
        avg_bin_search_lewo_c[i] += bin_search_lewo_c[i * 100 + j]
        avg_bin_search_lewo_t[i] += bin_search_lewo_t[i * 100 + j]
    avg_bin_search_lewo_c[i] /= 100
    avg_bin_search_lewo_t[i] /= 100

dane_str = []
dane = []

file = open("bin_search_srodek.txt")
dane_str = file.read().split()
file.close()

for i in dane_str:
    dane.append(int(i))

bin_search_srodek_n = dane[::3]
bin_search_srodek_c = dane[1::3]
bin_search_srodek_t = dane[2::3]

avg_bin_search_srodek_n = []
avg_bin_search_srodek_c = []
avg_bin_search_srodek_t = []

for i in range(100):
    avg_bin_search_srodek_n.append(bin_search_srodek_n[i * 100])
    avg_bin_search_srodek_c.append(0)
    avg_bin_search_srodek_t.append(0)
    for j in range(100):
        avg_bin_search_srodek_c[i] += bin_search_srodek_c[i * 100 + j]
        avg_bin_search_srodek_t[i] += bin_search_srodek_t[i * 100 + j]
    avg_bin_search_srodek_c[i] /= 100
    avg_bin_search_srodek_t[i] /= 100

dane_str = []
dane = []

file = open("bin_search_prawo.txt")
dane_str = file.read().split()
file.close()

for i in dane_str:
    dane.append(int(i))

bin_search_prawo_n = dane[::3]
bin_search_prawo_c = dane[1::3]
bin_search_prawo_t = dane[2::3]

avg_bin_search_prawo_n = []
avg_bin_search_prawo_c = []
avg_bin_search_prawo_t = []

for i in range(100):
    avg_bin_search_prawo_n.append(bin_search_prawo_n[i * 100])
    avg_bin_search_prawo_c.append(0)
    avg_bin_search_prawo_t.append(0)
    for j in range(100):
        avg_bin_search_prawo_c[i] += bin_search_prawo_c[i * 100 + j]
        avg_bin_search_prawo_t[i] += bin_search_prawo_t[i * 100 + j]
    avg_bin_search_prawo_c[i] /= 100
    avg_bin_search_prawo_t[i] /= 100

dane_str = []
dane = []

file = open("bin_search_rand.txt")
dane_str = file.read().split()
file.close()

for i in dane_str:
    dane.append(int(i))

bin_search_rand_n = dane[::3]
bin_search_rand_c = dane[1::3]
bin_search_rand_t = dane[2::3]

avg_bin_search_rand_n = []
avg_bin_search_rand_c = []
avg_bin_search_rand_t = []

for i in range(100):
    avg_bin_search_rand_n.append(bin_search_rand_n[i * 100])
    avg_bin_search_rand_c.append(0)
    avg_bin_search_rand_t.append(0)
    for j in range(100):
        avg_bin_search_rand_c[i] += bin_search_rand_c[i * 100 + j]
        avg_bin_search_rand_t[i] += bin_search_rand_t[i * 100 + j]
    avg_bin_search_rand_c[i] /= 100
    avg_bin_search_rand_t[i] /= 100

dane_str = []
dane = []

file = open("quick_new.txt")
dane_str = file.read().split()
file.close()

for i in dane_str:
    dane.append(int(i))

quick_new_n = dane[::3]
quick_new_c = dane[1::3]
quick_new_t = dane[2::3]

avg_quick_new_n = []
avg_quick_new_c = []
avg_quick_new_t = []

for i in range(100):
    avg_quick_new_n.append(quick_new_n[i * 100])
    avg_quick_new_c.append(0)
    avg_quick_new_t.append(0)
    for j in range(100):
        avg_quick_new_c[i] += quick_new_c[i * 100 + j]
        avg_quick_new_t[i] += quick_new_t[i * 100 + j]
    avg_quick_new_c[i] /= 100
    avg_quick_new_t[i] /= 100

dane_str = []
dane = []

file = open("quick_old.txt")
dane_str = file.read().split()
file.close()

for i in dane_str:
    dane.append(int(i))

quick_old_n = dane[::3]
quick_old_c = dane[1::3]
quick_old_t = dane[2::3]

avg_quick_old_n = []
avg_quick_old_c = []
avg_quick_old_t = []

for i in range(100):
    avg_quick_old_n.append(quick_old_n[i * 100])
    avg_quick_old_c.append(0)
    avg_quick_old_t.append(0)
    for j in range(100):
        avg_quick_old_c[i] += quick_old_c[i * 100 + j]
        avg_quick_old_t[i] += quick_old_t[i * 100 + j]
    avg_quick_old_c[i] /= 100
    avg_quick_old_t[i] /= 100

dane_str = []
dane = []

file = open("dual_quick_new.txt")
dane_str = file.read().split()
file.close()

for i in dane_str:
    dane.append(int(i))

dual_quick_new_n = dane[::3]
dual_quick_new_c = dane[1::3]
dual_quick_new_t = dane[2::3]

avg_dual_quick_new_n = []
avg_dual_quick_new_c = []
avg_dual_quick_new_t = []

for i in range(100):
    avg_dual_quick_new_n.append(dual_quick_new_n[i * 100])
    avg_dual_quick_new_c.append(0)
    avg_dual_quick_new_t.append(0)
    for j in range(100):
        avg_dual_quick_new_c[i] += dual_quick_new_c[i * 100 + j]
        avg_dual_quick_new_t[i] += dual_quick_new_t[i * 100 + j]
    avg_dual_quick_new_c[i] /= 100
    avg_dual_quick_new_t[i] /= 100

dane_str = []
dane = []

file = open("dual_quick_old.txt")
dane_str = file.read().split()
file.close()

for i in dane_str:
    dane.append(int(i))

dual_quick_old_n = dane[::3]
dual_quick_old_c = dane[1::3]
dual_quick_old_t = dane[2::3]

avg_dual_quick_old_n = []
avg_dual_quick_old_c = []
avg_dual_quick_old_t = []

for i in range(100):
    avg_dual_quick_old_n.append(dual_quick_old_n[i * 100])
    avg_dual_quick_old_c.append(0)
    avg_dual_quick_old_t.append(0)
    for j in range(100):
        avg_dual_quick_old_c[i] += dual_quick_old_c[i * 100 + j]
        avg_dual_quick_old_t[i] += dual_quick_old_t[i * 100 + j]
    avg_dual_quick_old_c[i] /= 100
    avg_dual_quick_old_t[i] /= 100

# Wykresy ifów swapów i czasu dla selectów


plt.figure(1)

plt.title("Wykres ilości porównań kluczy dla selectów")
plt.xlabel("n")
plt.ylabel("Średnia # porównań kluczy")

plt.plot(avg_select_n, avg_select_c, "b-", label = "Select")
plt.plot(avg_rand_select_n, avg_rand_select_c, "y-", label = "Random Select")
plt.plot(avg_select_5_3_n, avg_select_5_3_c, "g-", label = "Select Group 3")
plt.plot(avg_select_5_5_n, avg_select_5_5_c, "c-", label = "Select Group 5")
plt.plot(avg_select_5_7_n, avg_select_5_7_c, "m-", label = "Select Group 7")
plt.plot(avg_select_5_9_n, avg_select_5_9_c, "r-", label = "Select Group 9")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("wykresy/select_c.png", dpi=300)
plt.close()

plt.figure(2)

plt.title("Wykres ilości podmian kluczy dla selectów")
plt.xlabel("n")
plt.ylabel("Średnia # podmian kluczy")

plt.plot(avg_select_n, avg_select_s, "b-", label = "Select")
plt.plot(avg_rand_select_n, avg_rand_select_s, "y-", label = "Random Select")
plt.plot(avg_select_5_3_n, avg_select_5_3_s, "g-", label = "Select Group 3")
plt.plot(avg_select_5_5_n, avg_select_5_5_s, "c-", label = "Select Group 5")
plt.plot(avg_select_5_7_n, avg_select_5_7_s, "m-", label = "Select Group 7")
plt.plot(avg_select_5_9_n, avg_select_5_9_s, "r-", label = "Select Group 9")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("wykresy/select_s.png", dpi=300)
plt.close()

plt.figure(3)

plt.title("Wykres czasu dla selectów grupowanych")
plt.xlabel("n")
plt.ylabel("Średni czas")

plt.plot(avg_select_5_3_n, avg_select_5_3_t, "g-", label = "Select Group 3")
plt.plot(avg_select_5_5_n, avg_select_5_5_t, "c-", label = "Select Group 5")
plt.plot(avg_select_5_7_n, avg_select_5_7_t, "m-", label = "Select Group 7")
plt.plot(avg_select_5_9_n, avg_select_5_9_t, "r-", label = "Select Group 9")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("wykresy/select_t.png", dpi=300)
plt.close()

# Wykresy ilości porównań i czasu dal bin_search

plt.figure(4)

plt.title("Wykres ilości porównań kluczy dla binary search")
plt.xlabel("n")
plt.ylabel("Średnia # porównań kluczy")

plt.plot(avg_bin_search_lewo_n, avg_bin_search_lewo_c, "g-", label = "Element z początku")
plt.plot(avg_bin_search_srodek_n, avg_bin_search_srodek_c, "c-", label = "Element ze środka")
plt.plot(avg_bin_search_prawo_n, avg_bin_search_prawo_c, "m-", label = "Element Z końca")
plt.plot(avg_bin_search_rand_n, avg_bin_search_rand_c, "r-", label = "Losowy element")
x = np.linspace(1000, 100000, 1000, True)
plt.plot(x, np.log(x), "k-", label = "Master Theorem")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("wykresy/bin_search_c.png", dpi=300)
plt.close()

plt.figure(5)

plt.title("Wykres czasu dla binary search")
plt.xlabel("n")
plt.ylabel("Średni czas")

plt.plot(avg_bin_search_lewo_n, avg_bin_search_lewo_t, "g-", label = "Element z początku")
plt.plot(avg_bin_search_srodek_n, avg_bin_search_srodek_t, "c-", label = "Element ze środka")
plt.plot(avg_bin_search_prawo_n, avg_bin_search_prawo_t, "m-", label = "Element Z końca")
plt.plot(avg_bin_search_rand_n, avg_bin_search_rand_t, "r-", label = "Losowy element")
x = np.linspace(1000, 100000, 1000, True)
plt.plot(x, np.log(x), "k-", label = "Master Theorem")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("wykresy/bin_search_t.png", dpi=300)
plt.close()

# Wykresy ilości porównań i czasu dla quick sortów

plt.figure(6)

plt.title("Wykres ilości porównań kluczy dla quick sortów")
plt.xlabel("n")
plt.ylabel("Średnia # porównań kluczy")

plt.plot(avg_quick_new_n, avg_quick_new_c, "g-", label = "Nowy Quick sort")
plt.plot(avg_quick_old_n, avg_quick_old_c, "c-", label = "Stary Quick sort")
plt.plot(avg_dual_quick_new_n, avg_dual_quick_new_c, "m-", label = "Nowy Dual quick sort")
plt.plot(avg_dual_quick_old_n, avg_dual_quick_old_c, "r-", label = "Stary Dual quick sort")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("wykresy/quick_c.png", dpi=300)
plt.close()

plt.figure(7)

plt.title("Wykres czasu dla quick sortów")
plt.xlabel("n")
plt.ylabel("Średni czas")

plt.plot(avg_quick_new_n, avg_quick_new_t, "g-", label = "Nowy Quick sort")
plt.plot(avg_quick_old_n, avg_quick_old_t, "c-", label = "Stary Quick sort")
plt.plot(avg_dual_quick_new_n, avg_dual_quick_new_t, "m-", label = "Nowy Dual quick sort")
plt.plot(avg_dual_quick_old_n, avg_dual_quick_old_t, "r-", label = "Stary Dual quick sort")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("wykresy/quick_t.png", dpi=300)
plt.close()

plt.figure(8)

plt.title("Wykres ilości porównań kluczy dla quick sortów")
plt.xlabel("n")
plt.ylabel("Średnia # porównań kluczy")

plt.plot(avg_quick_new_n, avg_quick_new_c, "g-", label = "Nowy Quick sort")
plt.plot(avg_dual_quick_new_n, avg_dual_quick_new_c, "m-", label = "Nowy Dual quick sort")
plt.plot(avg_dual_quick_old_n, avg_dual_quick_old_c, "r-", label = "Stary Dual quick sort")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("wykresy/quick_c2.png", dpi=300)
plt.close()

plt.figure(9)

plt.title("Wykres czasu dla quick sortów")
plt.xlabel("n")
plt.ylabel("Średni czas")

plt.plot(avg_quick_new_n, avg_quick_new_t, "g-", label = "Nowy Quick sort")
plt.plot(avg_dual_quick_new_n, avg_dual_quick_new_t, "m-", label = "Nowy Dual quick sort")
plt.plot(avg_dual_quick_old_n, avg_dual_quick_old_t, "r-", label = "Stary Dual quick sort")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("wykresy/quick_t2.png", dpi=300)
plt.close()