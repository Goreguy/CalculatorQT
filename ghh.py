import numpy as np
from scipy.linalg import eigvals, norm
n = 5;
m = 6;
k1 = 4;
l = 3;
k = 4;
p = 2;
w = 1;
r = 3;
h = 3;
v = 3;
q = 3;
a1 = 4;
a2 = -6;
a3 = -7;
a4 = -4;
a5 = 3;
j = 7;
print("Задание 1")
A = np.array([
[5,4,4,5,10],
[4,9,1,9,7],
[7,10,2,10,10],
[1,8,9,8,5],
[6,9,1,10,3]], dtype=float)
print("Матрица A")
print(A)

B = np.array([
[8,0,8,5,5,4],
[4,4,7,3,5,0],
[3,6,0,7,10,9],
[0,9,5,9,7,5],
[6,5,8,1,10,3]], dtype=float)
print("Матрица B")
print(B)

C = np.array([
[8,3,10,0,6],
[0,3,10,6,8],
[4,3,3,6,3],
[5,6,2,1,5],
[0,4,10,0,10]], dtype=float)
print("Матрица C")
print(C)

# Умножение k-й строки на a1 и l-го столбца на 2a
Answer1 = A[k1 - 1, :] * a1
Answer2 = A[:, l-1] * a2
print("\nУмножение k-й строки и l-го столбца на a1 и a2 соответственно:\n")
print(Answer1)
print(Answer2)

# Сложение k-й строки с l-й, умноженной на a3
Answer3 = A[k-1, :] + a3 * A[l-1, :]
print("\nCложение k-й строки с l-й, умноженной на a3:\n")
print(Answer3)

# Сложение k-го и p-го столбцов, один из них умножен на a4
Answer4 = A[:, k-1] * a4 + A[:, p-1]
print("\nПосле сложения k-го и p-го столбцов, один умножен на a4:\n")
print(Answer4)

# Транспонирование матрицы
A_T = A.T
print("\nТранспонированная матрица A:\n", A_T)

# Ранг матрицы A
rank_A = np.linalg.matrix_rank(A)
print("\nРанг матрицы A:", rank_A)

# Обратная матрица A и проверка
if np.linalg.det(A) != 0:
    A_inv = np.linalg.inv(A)
    print("\nОбратная матрица A:\n", A_inv)
    # Проверка: A * A_inv
    identity_check = np.dot(A, A_inv)
    print("\nПроверка A * A_inv (должна быть единичной):\n", identity_check)
else:
    print("\nОбратная матрица A не существует (определитель равен нулю).")

# 7. Собственные числа и спектральный радиус
eigenvalues = eigvals(A)
spectral_radius = max(abs(eigenvalues))
print("\nСобственные числа матрицы A:", eigenvalues)
print("Спектральный радиус матрицы A:", spectral_radius)

# 8. Нормы матрицы A (2-норма, 1-норма, бесконечная норма)
norm_1 = norm(A, 1)
norm_2 = norm(A, 2)
norm_inf = norm(A, np.inf)
print("\n1-норма:", norm_1)
print("2-норма:", norm_2)
print("Бесконечная норма:", norm_inf)

# 9. Определитель матрицы A
det_A = np.linalg.det(A)
print("\nОпределитель матрицы A:", det_A)

# 10. Возведение матрицы A в степень q
A_q = np.linalg.matrix_power(A, q)
print(f"\nМатрица A в степени {q}:\n", A_q)

# 11. Выделение w-й строки, r-го столбца и подматрицы размером h x v
w_row = A[w-1, :]
r_col = A[:, r-1]
submatrix = A[:h, :v]
print("\nw-я строка матрицы A:", w_row)
print("r-й столбец матрицы A:\n", r_col)
print(f"Подматрица размером {h} на {v}:\n", submatrix)

# 12. Сумма и разность матриц A и C
A_plus_C = A + C
A_minus_C = A - C
print("\nСумма матриц A и C:\n", A_plus_C)
print("Разность матриц A и C:\n", A_minus_C)

# 13. Сумма и разность матриц A и C, умноженных на скаляр a5
A_scaled = a5 * A
C_scaled = a5 * C
A_plus_C_scaled = A_scaled + C_scaled
A_minus_C_scaled = A_scaled - C_scaled
print("\nСумма матриц A и C, умноженных на скаляр a5:\n", A_plus_C_scaled)
print("Разность матриц A и C, умноженных на скаляр a5:\n", A_minus_C_scaled)

# 14. Произведение матрицы A на B
A_dot_B = np.dot(A, B)
print("\nПроизведение матрицы A на B:\n", A_dot_B)

# 15. Формирование расширенной матрицы из A, B и C
extended_matrix = np.hstack([A, B, C])
print("\nРасширенная матрица из A, B и C:\n", extended_matrix)

# 16. Ранг расширенной матрицы
rank_extended = np.linalg.matrix_rank(extended_matrix)
print("\nРанг расширенной матрицы:", rank_extended)

print("Задание 2")
