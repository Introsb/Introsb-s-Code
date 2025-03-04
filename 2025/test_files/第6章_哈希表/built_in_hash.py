num = 3
hash_num = hash(num)
print(hash_num)
# 整数 3 的哈希值为 3

bol = True
hash_bol = hash(bol)
print(bol)
# 布尔值 True 的哈希值为 1

dec = 3.14159
hash_dec = hash(dec)
print(hash_dec)
# 小数 3.14159 的哈希值为 326484311674566659

str = "Hello 算法"
hash_str = hash(str)
print(hash_str)
# 字符串"hello 算法"的哈希值为 2727949105627458109

tup = (123,"爱爱爱")
hash_tup = hash(tup)
print(hash_tup)
# 元组的哈希值为 -2869158032432213218
