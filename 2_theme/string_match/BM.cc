/**
 * BM算法，取好坏部分，进行模式串的移动
 * 1.主串从左往右匹配模式串
 * 2.模式串从右往左每个字符匹配
 * 3.如果出现不匹配的字符，取坏字符规则和好字符规则中较大的值进行移动
 * 4.坏字符规则：看不匹配的值在模式串前面是否还有出现过，进行相应的移动
 * 5.好字符规则：先看好字符串在前面是否有出现，没有就看好字符的后缀子串是否是模式串的前缀子串，进行相应的移动
 * 6.技巧，模式串是固定的，可以预先构建一个查找某个字符在模式串位置的对象(方便后面查找坏字符)，构建一个后缀串是否在模式串出现和后缀串是否是前缀串的数组(方便进行好字符规则进行匹配)
 */
