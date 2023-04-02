import matplotlib.pyplot as plt
import numpy as np

file = open("insertion.txt")
str_insertion = file.read().split()
file.close()

insertion = []

for i in str_insertion:
    insertion.append(int(i))

insertion_n = insertion[::3]
insertion_c = insertion[1::3]
insertion_s = insertion[2::3]

avg_insertion_n = []
avg_insertion_c_100 = []
avg_insertion_s_100 = []
avg_insertion_c_10 = []
avg_insertion_s_10 = []
avg_insertion_c_n_100 = []
avg_insertion_s_n_100 = []
avg_insertion_c_n_10 = []
avg_insertion_s_n_10 = []
avg_insertion_c_n_1 = []
avg_insertion_s_n_1 = []
for i in range(int(len(insertion_c) / 100)):
    avg_insertion_n.append(insertion_n[i * 100])
    sum_c = 0
    sum_s = 0
    for j in range(100):
        sum_c += insertion_c[i * 100 + j]
        sum_s += insertion_s[i * 100 + j]
        if(j == 9):
            avg_insertion_c_n_1.append(insertion_c[i * 100] / insertion_n[i * 100])
            avg_insertion_s_n_1.append(insertion_s[i * 100] / insertion_n[i * 100])
            avg_insertion_c_10.append(sum_c / 10)
            avg_insertion_s_10.append(sum_s / 10)
            avg_insertion_c_n_10.append(sum_c / 10 / insertion_n[i * 100])
            avg_insertion_s_n_10.append(sum_s / 10 / insertion_n[i * 100])
    avg_insertion_c_100.append(sum_c / 100)
    avg_insertion_s_100.append(sum_s / 100)
    avg_insertion_c_n_100.append(sum_c / 100 / insertion_n[i * 100])
    avg_insertion_s_n_100.append(sum_s / 100 / insertion_n[i * 100])

file = open("merge.txt")
str_merge = file.read().split()
file.close()

merge = []

for i in str_merge:
    merge.append(int(i))

merge_n = merge[::3]
merge_c = merge[1::3]
merge_s = merge[2::3]

avg_merge_n = []
avg_merge_c_100 = []
avg_merge_s_100 = []
avg_merge_c_10 = []
avg_merge_s_10 = []
avg_merge_c_n_100 = []
avg_merge_s_n_100 = []
avg_merge_c_n_10 = []
avg_merge_s_n_10 = []
avg_merge_c_n_1 = []
avg_merge_s_n_1 = []

for i in range(int(len(merge_c) / 100)):
    avg_merge_n.append(merge_n[i * 100])
    sum_c = 0
    sum_s = 0
    for j in range(100):
        sum_c += merge_c[i * 100 + j]
        sum_s += merge_s[i * 100 + j]
        if(j == 9):
            avg_merge_c_n_1.append(merge_c[i * 100] / merge_n[i * 100])
            avg_merge_s_n_1.append(merge_s[i * 100] / merge_n[i * 100])
            avg_merge_c_10.append(sum_c / 10)
            avg_merge_s_10.append(sum_s / 10)
            avg_merge_c_n_10.append(sum_c / 10 / merge_n[i * 100])
            avg_merge_s_n_10.append(sum_s / 10 / merge_n[i * 100])
    avg_merge_c_100.append(sum_c / 100)
    avg_merge_s_100.append(sum_s / 100)
    avg_merge_c_n_100.append(sum_c / 100 / merge_n[i * 100])
    avg_merge_s_n_100.append(sum_s / 100 / merge_n[i * 100])

file = open("quick.txt")
str_quick = file.read().split()
file.close()

quick = []

for i in str_quick:
    quick.append(int(i))

quick_n = quick[::3]
quick_c = quick[1::3]
quick_s = quick[2::3]

avg_quick_n = []
avg_quick_c_100 = []
avg_quick_s_100 = []
avg_quick_c_10 = []
avg_quick_s_10 = []
avg_quick_c_n_100 = []
avg_quick_s_n_100 = []
avg_quick_c_n_10 = []
avg_quick_s_n_10 = []
avg_quick_c_n_1 = []
avg_quick_s_n_1 = []
for i in range(int(len(quick_c) / 100)):
    avg_quick_n.append(quick_n[i * 100])
    sum_c = 0
    sum_s = 0
    for j in range(100):
        sum_c += quick_c[i * 100 + j]
        sum_s += quick_s[i * 100 + j]
        if(j == 9):
            avg_quick_c_n_1.append(quick_c[i * 100] / quick_n[i * 100])
            avg_quick_s_n_1.append(quick_s[i * 100] / quick_n[i * 100])
            avg_quick_c_10.append(sum_c / 10)
            avg_quick_s_10.append(sum_s / 10)
            avg_quick_c_n_10.append(sum_c / 10 / quick_n[i * 100])
            avg_quick_s_n_10.append(sum_s / 10 / quick_n[i * 100])
    avg_quick_c_100.append(sum_c / 100)
    avg_quick_s_100.append(sum_s / 100)
    avg_quick_c_n_100.append(sum_c / 100 / quick_n[i * 100])
    avg_quick_s_n_100.append(sum_s / 100 / quick_n[i * 100])

file = open("dual_quick.txt")
str_dual_quick = file.read().split()
file.close()

dual_quick = []

for i in str_dual_quick:
    dual_quick.append(int(i))

dual_quick_n = dual_quick[::3]
dual_quick_c = dual_quick[1::3]
dual_quick_s = dual_quick[2::3]

avg_dual_quick_n = []
avg_dual_quick_c_100 = []
avg_dual_quick_s_100 = []
avg_dual_quick_c_10 = []
avg_dual_quick_s_10 = []
avg_dual_quick_c_n_100 = []
avg_dual_quick_s_n_100 = []
avg_dual_quick_c_n_10 = []
avg_dual_quick_s_n_10 = []
avg_dual_quick_c_n_1 = []
avg_dual_quick_s_n_1 = []
for i in range(int(len(dual_quick_c) / 100)):
    avg_dual_quick_n.append(dual_quick_n[i * 100])
    sum_c = 0
    sum_s = 0
    for j in range(100):
        sum_c += dual_quick_c[i * 100 + j]
        sum_s += dual_quick_s[i * 100 + j]
        if(j == 9):
            avg_dual_quick_c_n_1.append(dual_quick_c[i * 100] / dual_quick_n[i * 100])
            avg_dual_quick_s_n_1.append(dual_quick_s[i * 100] / dual_quick_n[i * 100])
            avg_dual_quick_c_10.append(sum_c / 10)
            avg_dual_quick_s_10.append(sum_s / 10)
            avg_dual_quick_c_n_10.append(sum_c / 10 / dual_quick_n[i * 100])
            avg_dual_quick_s_n_10.append(sum_s / 10 / dual_quick_n[i * 100])
    avg_dual_quick_c_100.append(sum_c / 100)
    avg_dual_quick_s_100.append(sum_s / 100)
    avg_dual_quick_c_n_100.append(sum_c / 100 / dual_quick_n[i * 100])
    avg_dual_quick_s_n_100.append(sum_s / 100 / dual_quick_n[i * 100])

file = open("hybrid.txt")
str_hybrid = file.read().split()
file.close()

hybrid = []

for i in str_hybrid:
    hybrid.append(int(i))

hybrid_n = hybrid[::3]
hybrid_c = hybrid[1::3]
hybrid_s = hybrid[2::3]

avg_hybrid_n = []
avg_hybrid_c_100 = []
avg_hybrid_s_100 = []
avg_hybrid_c_10 = []
avg_hybrid_s_10 = []
avg_hybrid_c_n_100 = []
avg_hybrid_s_n_100 = []
avg_hybrid_c_n_10 = []
avg_hybrid_s_n_10 = []
avg_hybrid_c_n_1 = []
avg_hybrid_s_n_1 = []
for i in range(int(len(hybrid_c) / 100)):
    avg_hybrid_n.append(hybrid_n[i * 100])
    sum_c = 0
    sum_s = 0
    for j in range(100):
        sum_c += hybrid_c[i * 100 + j]
        sum_s += hybrid_s[i * 100 + j]
        if(j == 9):
            avg_hybrid_c_n_1.append(hybrid_c[i * 100] / hybrid_n[i * 100])
            avg_hybrid_s_n_1.append(hybrid_s[i * 100] / hybrid_n[i * 100])
            avg_hybrid_c_10.append(sum_c / 10)
            avg_hybrid_s_10.append(sum_s / 10)
            avg_hybrid_c_n_10.append(sum_c / 10 / hybrid_n[i * 100])
            avg_hybrid_s_n_10.append(sum_s / 10 / hybrid_n[i * 100])
    avg_hybrid_c_100.append(sum_c / 100)
    avg_hybrid_s_100.append(sum_s / 100)
    avg_hybrid_c_n_100.append(sum_c / 100 / hybrid_n[i * 100])
    avg_hybrid_s_n_100.append(sum_s / 100 / hybrid_n[i * 100])

# c oraz s male dla kazdego k

plt.figure(1)

plt.title("Wykresy dla n = {10, ... , 200} k = 100")
plt.xlabel("n")
plt.ylabel("Średnia # porównań kluczy")

plt.plot(avg_insertion_n, avg_insertion_c_100, "b-o", label = "Insertion Sort")
plt.plot(avg_merge_n[:20], avg_merge_c_100[:20], "y-o", label = "Merge Sort")
plt.plot(avg_quick_n[:20], avg_quick_c_100[:20], "g-o", label = "Quick Sort")
plt.plot(avg_dual_quick_n[:20], avg_dual_quick_c_100[:20], "c-o", label = "Dual Pivot Quick Sort")
plt.plot(avg_hybrid_n[:20], avg_hybrid_c_100[:20], "r-o", label = "Hybrid Sort")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("c_100.png", dpi=300)
plt.close()

plt.figure(2)

plt.title("Wykresy dla n = {10, ... , 200} k = 100")
plt.xlabel("n")
plt.ylabel("Średnia # podmian kluczy")

plt.plot(avg_insertion_n, avg_insertion_s_100, "b-o", label = "Insertion Sort")
plt.plot(avg_merge_n[:20], avg_merge_s_100[:20], "y-o", label = "Merge Sort")
plt.plot(avg_quick_n[:20], avg_quick_s_100[:20], "g-o", label = "Quick Sort")
plt.plot(avg_dual_quick_n[:20], avg_dual_quick_s_100[:20], "c-o", label = "Dual Pivot Quick Sort")
plt.plot(avg_hybrid_n[:20], avg_hybrid_s_100[:20], "r-o", label = "Hybrid Sort")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("s_100.png", dpi=300)
plt.close()

plt.figure(3)

plt.title("Wykresy dla n = {10, ... , 200} k = 10")
plt.xlabel("n")
plt.ylabel("Średnia # porównań kluczy")

plt.plot(avg_insertion_n, avg_insertion_c_10, "b-o", label = "Insertion Sort")
plt.plot(avg_merge_n[:20], avg_merge_c_10[:20], "y-o", label = "Merge Sort")
plt.plot(avg_quick_n[:20], avg_quick_c_10[:20], "g-o", label = "Quick Sort")
plt.plot(avg_dual_quick_n[:20], avg_dual_quick_c_10[:20], "c-o", label = "Dual Pivot Quick Sort")
plt.plot(avg_hybrid_n[:20], avg_hybrid_c_10[:20], "r-o", label = "Hybrid Sort")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("c_10.png", dpi=300)
plt.close()

plt.figure(4)

plt.title("Wykresy dla n = {10, ... , 200} k = 10")
plt.xlabel("n")
plt.ylabel("Średnia # podmian kluczy")

plt.plot(avg_insertion_n, avg_insertion_s_10, "b-o", label = "Insertion Sort")
plt.plot(avg_merge_n[:20], avg_merge_s_10[:20], "y-o", label = "Merge Sort")
plt.plot(avg_quick_n[:20], avg_quick_s_10[:20], "g-o", label = "Quick Sort")
plt.plot(avg_dual_quick_n[:20], avg_dual_quick_s_10[:20], "c-o", label = "Dual Pivot Quick Sort")
plt.plot(avg_hybrid_n[:20], avg_hybrid_s_10[:20], "r-o", label = "Hybrid Sort")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("s_10.png", dpi=300)
plt.close()

plt.figure(5)

plt.title("Wykresy dla n = {10, ... , 200} k = 1")
plt.xlabel("n")
plt.ylabel("Średnia # porównań kluczy")

plt.plot(avg_insertion_n, insertion_c[::100], "b-o", label = "Insertion Sort")
plt.plot(avg_merge_n[:20], merge_c[:20*100:100], "y-o", label = "Merge Sort")
plt.plot(avg_quick_n[:20], quick_c[:20*100:100], "g-o", label = "Quick Sort")
plt.plot(avg_dual_quick_n[:20], dual_quick_c[:20*100:100], "c-o", label = "Dual Pivot Quick Sort")
plt.plot(avg_hybrid_n[:20], hybrid_c[:20*100:100], "r-o", label = "Hybrid Sort")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("c_1.png", dpi=300)
plt.close()

plt.figure(6)

plt.title("Wykresy dla n = {10, ... , 200} k = 1")
plt.xlabel("n")
plt.ylabel("Średnia # podmian kluczy")

plt.plot(avg_insertion_n, insertion_s[::100], "b-o", label = "Insertion Sort")
plt.plot(avg_merge_n[:20], merge_s[:20*100:100], "y-o", label = "Merge Sort")
plt.plot(avg_quick_n[:20], quick_s[:20*100:100], "g-o", label = "Quick Sort")
plt.plot(avg_dual_quick_n[:20], dual_quick_s[:20*100:100], "c-o", label = "Dual Pivot Quick Sort")
plt.plot(avg_hybrid_n[:20], hybrid_s[:20*100:100], "r-o", label = "Hybrid Sort")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("s_1.png", dpi=300)
plt.close()

# c oraz s duze dla kazdego k

plt.figure(7)

plt.title("Wykresy dla n = {1000, ... , 20000} k = 100")
plt.xlabel("n")
plt.ylabel("Średnia # porównań kluczy")

plt.plot(avg_merge_n[20:], avg_merge_c_100[20:], "y-o", label = "Merge Sort")
plt.plot(avg_quick_n[20:], avg_quick_c_100[20:], "g-o", label = "Quick Sort")
plt.plot(avg_dual_quick_n[20:], avg_dual_quick_c_100[20:], "c-o", label = "Dual Pivot Quick Sort")
plt.plot(avg_hybrid_n[20:], avg_hybrid_c_100[20:], "r-o", label = "Hybrid Sort")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("c_100_big.png", dpi=300)
plt.close()

plt.figure(8)

plt.title("Wykresy dla n = {1000, ... , 20000} k = 100")
plt.xlabel("n")
plt.ylabel("Średnia # podmian kluczy")

plt.plot(avg_merge_n[20:], avg_merge_s_100[20:], "y-o", label = "Merge Sort")
plt.plot(avg_quick_n[20:], avg_quick_s_100[20:], "g-o", label = "Quick Sort")
plt.plot(avg_dual_quick_n[20:], avg_dual_quick_s_100[20:], "c-o", label = "Dual Pivot Quick Sort")
plt.plot(avg_hybrid_n[20:], avg_hybrid_s_100[20:], "r-o", label = "Hybrid Sort")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("s_100_big.png", dpi=300)
plt.close()

plt.figure(9)

plt.title("Wykresy dla n = {1000, ... , 20000} k = 10")
plt.xlabel("n")
plt.ylabel("Średnia # porównań kluczy")

plt.plot(avg_merge_n[20:], avg_merge_c_10[20:], "y-o", label = "Merge Sort")
plt.plot(avg_quick_n[20:], avg_quick_c_10[20:], "g-o", label = "Quick Sort")
plt.plot(avg_dual_quick_n[20:], avg_dual_quick_c_10[20:], "c-o", label = "Dual Pivot Quick Sort")
plt.plot(avg_hybrid_n[20:], avg_hybrid_c_10[20:], "r-o", label = "Hybrid Sort")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("c_10_big.png", dpi=300)
plt.close()

plt.figure(10)

plt.title("Wykresy dla n = {1000, ... , 20000} k = 10")
plt.xlabel("n")
plt.ylabel("Średnia # podmian kluczy")

plt.plot(avg_merge_n[20:], avg_merge_s_10[20:], "y-o", label = "Merge Sort")
plt.plot(avg_quick_n[20:], avg_quick_s_10[20:], "g-o", label = "Quick Sort")
plt.plot(avg_dual_quick_n[20:], avg_dual_quick_s_10[20:], "c-o", label = "Dual Pivot Quick Sort")
plt.plot(avg_hybrid_n[20:], avg_hybrid_s_10[20:], "r-o", label = "Hybrid Sort")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("s_10_big.png", dpi=300)
plt.close()

plt.figure(11)

plt.title("Wykresy dla n = {1000, ... , 20000} k = 1")
plt.xlabel("n")
plt.ylabel("Średnia # porównań kluczy")

plt.plot(avg_merge_n[20:], merge_c[20*100::100], "y-o", label = "Merge Sort")
plt.plot(avg_quick_n[20:], quick_c[20*100::100], "g-o", label = "Quick Sort")
plt.plot(avg_dual_quick_n[20:], dual_quick_c[20*100::100], "c-o", label = "Dual Pivot Quick Sort")
plt.plot(avg_hybrid_n[20:], hybrid_c[20*100::100], "r-o", label = "Hybrid Sort")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("c_1_big.png", dpi=300)
plt.close()

plt.figure(12)

plt.title("Wykresy dla n = {1000, ... , 20000} k = 1")
plt.xlabel("n")
plt.ylabel("Średnia # podmian kluczy")

plt.plot(avg_merge_n[20:], merge_s[20*100::100], "y-o", label = "Merge Sort")
plt.plot(avg_quick_n[20:], quick_s[20*100::100], "g-o", label = "Quick Sort")
plt.plot(avg_dual_quick_n[20:], dual_quick_s[20*100::100], "c-o", label = "Dual Pivot Quick Sort")
plt.plot(avg_hybrid_n[20:], hybrid_s[20*100::100], "r-o", label = "Hybrid Sort")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("s_1_big.png", dpi=300)
plt.close()

# c/n oraz s/n male dla kazdego k

plt.figure(13)

plt.title("Wykresy dla n = {10, ... , 200} k = 100")
plt.xlabel("n")
plt.ylabel("Średnia # porównań kluczy / n")

plt.plot(avg_insertion_n, avg_insertion_c_n_100, "b-o", label = "Insertion Sort")
plt.plot(avg_merge_n[:20], avg_merge_c_n_100[:20], "y-o", label = "Merge Sort")
plt.plot(avg_quick_n[:20], avg_quick_c_n_100[:20], "g-o", label = "Quick Sort")
plt.plot(avg_dual_quick_n[:20], avg_dual_quick_c_n_100[:20], "c-o", label = "Dual Pivot Quick Sort")
plt.plot(avg_hybrid_n[:20], avg_hybrid_c_n_100[:20], "r-o", label = "Hybrid Sort")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("c_n_100.png", dpi=300)
plt.close()

plt.figure(14)

plt.title("Wykresy dla n = {10, ... , 200} k = 100")
plt.xlabel("n")
plt.ylabel("Średnia # podmian kluczy / n")

plt.plot(avg_insertion_n, avg_insertion_s_n_100, "b-o", label = "Insertion Sort")
plt.plot(avg_merge_n[:20], avg_merge_s_n_100[:20], "y-o", label = "Merge Sort")
plt.plot(avg_quick_n[:20], avg_quick_s_n_100[:20], "g-o", label = "Quick Sort")
plt.plot(avg_dual_quick_n[:20], avg_dual_quick_s_n_100[:20], "c-o", label = "Dual Pivot Quick Sort")
plt.plot(avg_hybrid_n[:20], avg_hybrid_s_n_100[:20], "r-o", label = "Hybrid Sort")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("s_n_100.png", dpi=300)
plt.close()

plt.figure(15)

plt.title("Wykresy dla n = {10, ... , 200} k = 10")
plt.xlabel("n")
plt.ylabel("Średnia # porównań kluczy / n")

plt.plot(avg_insertion_n, avg_insertion_c_n_10, "b-o", label = "Insertion Sort")
plt.plot(avg_merge_n[:20], avg_merge_c_n_10[:20], "y-o", label = "Merge Sort")
plt.plot(avg_quick_n[:20], avg_quick_c_n_10[:20], "g-o", label = "Quick Sort")
plt.plot(avg_dual_quick_n[:20], avg_dual_quick_c_n_10[:20], "c-o", label = "Dual Pivot Quick Sort")
plt.plot(avg_hybrid_n[:20], avg_hybrid_c_n_10[:20], "r-o", label = "Hybrid Sort")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("c_n_10.png", dpi=300)
plt.close()

plt.figure(16)

plt.title("Wykresy dla n = {10, ... , 200} k = 10")
plt.xlabel("n")
plt.ylabel("Średnia # podmian kluczy / n")

plt.plot(avg_insertion_n, avg_insertion_s_n_10, "b-o", label = "Insertion Sort")
plt.plot(avg_merge_n[:20], avg_merge_s_n_10[:20], "y-o", label = "Merge Sort")
plt.plot(avg_quick_n[:20], avg_quick_s_n_10[:20], "g-o", label = "Quick Sort")
plt.plot(avg_dual_quick_n[:20], avg_dual_quick_s_n_10[:20], "c-o", label = "Dual Pivot Quick Sort")
plt.plot(avg_hybrid_n[:20], avg_hybrid_s_n_10[:20], "r-o", label = "Hybrid Sort")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("s_n_10.png", dpi=300)
plt.close()

plt.figure(17)

plt.title("Wykresy dla n = {10, ... , 200} k = 1")
plt.xlabel("n")
plt.ylabel("Średnia # porównań kluczy / n")

plt.plot(avg_insertion_n, avg_insertion_c_n_1, "b-o", label = "Insertion Sort")
plt.plot(avg_merge_n[:20], avg_merge_c_n_1[:20], "y-o", label = "Merge Sort")
plt.plot(avg_quick_n[:20], avg_quick_c_n_1[:20], "g-o", label = "Quick Sort")
plt.plot(avg_dual_quick_n[:20], avg_dual_quick_c_n_1[:20], "c-o", label = "Dual Pivot Quick Sort")
plt.plot(avg_hybrid_n[:20], avg_hybrid_c_n_1[:20], "r-o", label = "Hybrid Sort")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("c_n_1.png", dpi=300)
plt.close()

plt.figure(18)

plt.title("Wykresy dla n = {10, ... , 200} k = 1")
plt.xlabel("n")
plt.ylabel("Średnia # podmian kluczy / n")

plt.plot(avg_insertion_n, avg_insertion_s_n_1, "b-o", label = "Insertion Sort")
plt.plot(avg_merge_n[:20], avg_merge_s_n_1[:20], "y-o", label = "Merge Sort")
plt.plot(avg_quick_n[:20], avg_quick_s_n_1[:20], "g-o", label = "Quick Sort")
plt.plot(avg_dual_quick_n[:20], avg_dual_quick_s_n_1[:20], "c-o", label = "Dual Pivot Quick Sort")
plt.plot(avg_hybrid_n[:20], avg_hybrid_s_n_1[:20], "r-o", label = "Hybrid Sort")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("s_n_1.png", dpi=300)
plt.close()

# c/n oraz s/n duze dla kazdego k

plt.figure(19)

plt.title("Wykresy dla n = {1000, ... , 20000} k = 100")
plt.xlabel("n")
plt.ylabel("Średnia # porównań kluczy / n")

plt.plot(avg_merge_n[20:], avg_merge_c_n_100[20:], "y-o", label = "Merge Sort")
plt.plot(avg_quick_n[20:], avg_quick_c_n_100[20:], "g-o", label = "Quick Sort")
plt.plot(avg_dual_quick_n[20:], avg_dual_quick_c_n_100[20:], "c-o", label = "Dual Pivot Quick Sort")
plt.plot(avg_hybrid_n[20:], avg_hybrid_c_n_100[20:], "r-o", label = "Hybrid Sort")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("c_n_100_big.png", dpi=300)
plt.close()

plt.figure(20)

plt.title("Wykresy dla n = {1000, ... , 20000} k = 100")
plt.xlabel("n")
plt.ylabel("Średnia # podmian kluczy / n")

plt.plot(avg_merge_n[20:], avg_merge_s_n_100[20:], "y-o", label = "Merge Sort")
plt.plot(avg_quick_n[20:], avg_quick_s_n_100[20:], "g-o", label = "Quick Sort")
plt.plot(avg_dual_quick_n[20:], avg_dual_quick_s_n_100[20:], "c-o", label = "Dual Pivot Quick Sort")
plt.plot(avg_hybrid_n[20:], avg_hybrid_s_n_100[20:], "r-o", label = "Hybrid Sort")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("s_n_100_big.png", dpi=300)
plt.close()

plt.figure(21)

plt.title("Wykresy dla n = {1000, ... , 20000} k = 10")
plt.xlabel("n")
plt.ylabel("Średnia # porównań kluczy / n")

plt.plot(avg_merge_n[20:], avg_merge_c_n_10[20:], "y-o", label = "Merge Sort")
plt.plot(avg_quick_n[20:], avg_quick_c_n_10[20:], "g-o", label = "Quick Sort")
plt.plot(avg_dual_quick_n[20:], avg_dual_quick_c_n_10[20:], "c-o", label = "Dual Pivot Quick Sort")
plt.plot(avg_hybrid_n[20:], avg_hybrid_c_n_10[20:], "r-o", label = "Hybrid Sort")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("c_n_10_big.png", dpi=300)
plt.close()

plt.figure(22)

plt.title("Wykresy dla n = {1000, ... , 20000} k = 10")
plt.xlabel("n")
plt.ylabel("Średnia # podmian kluczy / n")

plt.plot(avg_merge_n[20:], avg_merge_s_n_10[20:], "y-o", label = "Merge Sort")
plt.plot(avg_quick_n[20:], avg_quick_s_n_10[20:], "g-o", label = "Quick Sort")
plt.plot(avg_dual_quick_n[20:], avg_dual_quick_s_n_10[20:], "c-o", label = "Dual Pivot Quick Sort")
plt.plot(avg_hybrid_n[20:], avg_hybrid_s_n_10[20:], "r-o", label = "Hybrid Sort")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("s_n_10_big.png", dpi=300)
plt.close()

plt.figure(23)

plt.title("Wykresy dla n = {1000, ... , 20000} k = 1")
plt.xlabel("n")
plt.ylabel("Średnia # porównań kluczy / n")

plt.plot(avg_merge_n[20:], avg_merge_c_n_1[20:], "y-o", label = "Merge Sort")
plt.plot(avg_quick_n[20:], avg_quick_c_n_1[20:], "g-o", label = "Quick Sort")
plt.plot(avg_dual_quick_n[20:], avg_dual_quick_c_n_1[20:], "c-o", label = "Dual Pivot Quick Sort")
plt.plot(avg_hybrid_n[20:], avg_hybrid_c_n_1[20:], "r-o", label = "Hybrid Sort")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("c_n_1_big.png", dpi=300)
plt.close()

plt.figure(24)

plt.title("Wykresy dla n = {1000, ... , 20000} k = 1")
plt.xlabel("n")
plt.ylabel("Średnia # podmian kluczy / n")

plt.plot(avg_merge_n[20:], avg_merge_s_n_1[20:], "y-o", label = "Merge Sort")
plt.plot(avg_quick_n[20:], avg_quick_s_n_1[20:], "g-o", label = "Quick Sort")
plt.plot(avg_dual_quick_n[20:], avg_dual_quick_s_n_1[20:], "c-o", label = "Dual Pivot Quick Sort")
plt.plot(avg_hybrid_n[20:], avg_hybrid_s_n_1[20:], "r-o", label = "Hybrid Sort")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("s_n_1_big.png", dpi=300)
plt.close()