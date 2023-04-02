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
avg_insertion_c = []
avg_insertion_s = []
for i in range(int(len(insertion_c) / 100)):
    avg_insertion_n.append(insertion_n[i * 100])
    sum_c = 0
    sum_s = 0
    for j in range(100):
        sum_c += insertion_c[i * 100 + j]
        sum_s += insertion_s[i * 100 + j]
    avg_insertion_c.append(sum_c / 100)
    avg_insertion_s.append(sum_s / 100)

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
avg_merge_c = []
avg_merge_s = []
for i in range(int(len(merge_c) / 100)):
    avg_merge_n.append(merge_n[i * 100])
    sum_c = 0
    sum_s = 0
    for j in range(100):
        sum_c += merge_c[i * 100 + j]
        sum_s += merge_s[i * 100 + j]
    avg_merge_c.append(sum_c / 100)
    avg_merge_s.append(sum_s / 100)

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
avg_quick_c = []
avg_quick_s = []
for i in range(int(len(quick_c) / 100)):
    avg_quick_n.append(quick_n[i * 100])
    sum_c = 0
    sum_s = 0
    for j in range(100):
        sum_c += quick_c[i * 100 + j]
        sum_s += quick_s[i * 100 + j]
    avg_quick_c.append(sum_c / 100)
    avg_quick_s.append(sum_s / 100)

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
avg_dual_quick_c = []
avg_dual_quick_s = []
for i in range(int(len(dual_quick_c) / 100)):
    avg_dual_quick_n.append(dual_quick_n[i * 100])
    sum_c = 0
    sum_s = 0
    for j in range(100):
        sum_c += dual_quick_c[i * 100 + j]
        sum_s += dual_quick_s[i * 100 + j]
    avg_dual_quick_c.append(sum_c / 100)
    avg_dual_quick_s.append(sum_s / 100)

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
avg_hybrid_c = []
avg_hybrid_s = []
for i in range(int(len(hybrid_c) / 100)):
    avg_hybrid_n.append(hybrid_n[i * 100])
    sum_c = 0
    sum_s = 0
    for j in range(100):
        sum_c += hybrid_c[i * 100 + j]
        sum_s += hybrid_s[i * 100 + j]
    avg_hybrid_c.append(sum_c / 100)
    avg_hybrid_s.append(sum_s / 100)



plt.figure(1)

plt.title("Wykresy dla n = {10, ... , 200}")
plt.xlabel("n")
plt.ylabel("Średnia # porównań kluczy")

plt.plot(avg_insertion_n, avg_insertion_c, "b-o", label = "Insertion Sort")
plt.plot(avg_merge_n[:20], avg_merge_c[:20], "y-o", label = "Merge Sort")
plt.plot(avg_quick_n[:20], avg_quick_c[:20], "g-o", label = "Quick Sort")
plt.plot(avg_dual_quick_n[:20], avg_dual_quick_c[:20], "c-o", label = "Dual Pivot Quick Sort")
plt.plot(avg_hybrid_n[:20], avg_hybrid_c[:20], "r-o", label = "Hybrid Sort")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("c_ins.png", dpi=300)

plt.figure(2)

plt.title("Wykresy dla n = {10, ... , 200}")
plt.xlabel("n")
plt.ylabel("Średnia # podmian kluczy")

plt.plot(avg_insertion_n, avg_insertion_s, "b-o", label = "Insertion Sort")
plt.plot(avg_merge_n[:20], avg_merge_s[:20], "y-o", label = "Merge Sort")
plt.plot(avg_quick_n[:20], avg_quick_s[:20], "g-o", label = "Quick Sort")
plt.plot(avg_dual_quick_n[:20], avg_dual_quick_s[:20], "c-o", label = "Dual Pivot Quick Sort")
plt.plot(avg_hybrid_n[:20], avg_hybrid_s[:20], "r-o", label = "Hybrid Sort")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("s_ins.png", dpi=300)

plt.figure(3)

plt.title("Wykresy dla n = {10, ... , 200} bez Insertion_Sort")
plt.xlabel("n")
plt.ylabel("Średnia # porównań kluczy")

plt.plot(avg_merge_n[:20], avg_merge_c[:20], "y-o", label = "Merge Sort")
plt.plot(avg_quick_n[:20], avg_quick_c[:20], "g-o", label = "Quick Sort")
plt.plot(avg_dual_quick_n[:20], avg_dual_quick_c[:20], "c-o", label = "Dual Pivot Quick Sort")
plt.plot(avg_hybrid_n[:20], avg_hybrid_c[:20], "r-o", label = "Hybrid Sort")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("c.png", dpi=300)

plt.figure(4)

plt.title("Wykresy dla n = {10, ... , 200} bez Insertion_Sort")
plt.xlabel("n")
plt.ylabel("Średnia # podmian kluczy")

plt.plot(avg_merge_n[:20], avg_merge_s[:20], "y-o", label = "Merge Sort")
plt.plot(avg_quick_n[:20], avg_quick_s[:20], "g-o", label = "Quick Sort")
plt.plot(avg_dual_quick_n[:20], avg_dual_quick_s[:20], "c-o", label = "Dual Pivot Quick Sort")
plt.plot(avg_hybrid_n[:20], avg_hybrid_s[:20], "r-o", label = "Hybrid Sort")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("s.png", dpi=300)

plt.figure(5)

plt.title("Wykresy dla n = {1000, ... , 20000}")
plt.xlabel("n")
plt.ylabel("Średnia # porównań kluczy")

plt.plot(avg_merge_n[21:], avg_merge_c[21:], "y-o", label = "Merge Sort")
plt.plot(avg_quick_n[21:], avg_quick_c[21:], "g-o", label = "Quick Sort")
plt.plot(avg_dual_quick_n[21:], avg_dual_quick_c[21:], "c-o", label = "Dual Pivot Quick Sort")
plt.plot(avg_hybrid_n[21:], avg_hybrid_c[21:], "r-o", label = "Hybrid Sort")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("c_big.png", dpi=300)

plt.figure(6)

plt.title("Wykresy dla n = {1000, ... , 20000}")
plt.xlabel("n")
plt.ylabel("Średnia # podmian kluczy")

plt.plot(avg_merge_n[21:], avg_merge_s[21:], "y-o", label = "Merge Sort")
plt.plot(avg_quick_n[21:], avg_quick_s[21:], "g-o", label = "Quick Sort")
plt.plot(avg_dual_quick_n[21:], avg_dual_quick_s[21:], "c-o", label = "Dual Pivot Quick Sort")
plt.plot(avg_hybrid_n[21:], avg_hybrid_s[21:], "r-o", label = "Hybrid Sort")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("s_big.png", dpi=300)