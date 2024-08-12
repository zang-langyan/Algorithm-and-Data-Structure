local UnionFind = {}
UnionFind.__index = UnionFind


function UnionFind:new(n)
  self = setmetatable({}, self)
  self.group_cnt = n
  self.elements_cnt = n
  self.id = {}
  self.sz = {}
  for i = 1, n do
    self.id[i] = i -- group id each element belongs to 
    self.sz[i] = 1 -- group size each element belongs to has
  end
  return self
end

function UnionFind:find(p)
  while p ~= self.id[p] do
    p = self.id[p]
  end
  return p
end

function UnionFind:insert_union(p, q)
  local pRoot = self:find(p)
  local qRoot = self:find(q)
  if pRoot == qRoot then
    return
  end

  if self.sz[pRoot] < self.sz[qRoot] then
    self.id[pRoot] = qRoot
    self.sz[qRoot] = self.sz[qRoot] + self.sz[pRoot]
  else
    self.id[qRoot] = pRoot
    self.sz[pRoot] = self.sz[pRoot] + self.sz[qRoot]
  end

  self.group_cnt = self.group_cnt - 1
end

function UnionFind:connected(p, q)
  return self:find(p) == self:find(q)
end


function UnionFind:print()
  for i = 1, self.elements_cnt do
    print(i, "->", self.id[i])
  end
end

-- Test
local UF = UnionFind:new(10)
UF:insert_union(4,3)
UF:print()

return UnionFind
