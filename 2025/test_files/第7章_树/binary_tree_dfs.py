from binary_tree import TreeNode

def pre_order(root: TreeNode | None, res=None):
    """前序遍历"""
    if res is None:
        res = []  # 初始化列表
    if root is None:
        return res  # 终止递归
    # 访问优先级：根节点 -> 左子树 -> 右子树
    res.append(root.val)
    pre_order(root.left, res)
    pre_order(root.right, res)
    return res

def in_order(root: TreeNode | None, res=None):
    """中序遍历"""
    if res is None:
        res = []
    if root is None:
        return res
    # 访问优先级：左子树 -> 根节点 -> 右子树
    in_order(root.left, res)
    res.append(root.val)
    in_order(root.right, res)
    return res

def post_order(root: TreeNode | None, res=None):
    """后序遍历"""
    if res is None:
        res = []
    if root is None:
        return res
    # 访问优先级：左子树 -> 右子树 -> 根节点
    post_order(root.left, res)
    post_order(root.right, res)
    res.append(root.val)
    return res
