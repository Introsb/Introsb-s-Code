def add_hash(key: str) -> int:
    """加法哈希"""
    hash = 0
    modules = 1000000007
    for c in key:
        hash += ord(c)
        return hash % modules
    
def mul_hash(key: str) -> int:
    """乘法哈希"""
    hash = 0
    modules = 1000000007
    for c in key:
        hash = 31 * hash + ord(c)
    return hash % modules

def xor_hash(key: str) -> int:
    """异或哈希"""
    hash = 0
    modules = 1000000007
    for c in key:
        hash ^= ord(c)
    return hash % modules

def rot_hash(key: str) -> int:
    """旋转哈希"""
    hash = 0
    modules = 1000000007
    for c in key:
        hash = (hash << 4) ^ (hash >> 28) ^ ord(c)
    return hash % modules