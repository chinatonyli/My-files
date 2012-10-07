set nocompatible "不要受限于vi
 
set cindent "使用C语言缩进
"程序中所有的制表符和缩进，都会以四个空格替代
set expandtab
set tabstop=4
set shiftwidth=4
set autochdir "自动切换工作目录
set clipboard+=unnamed "共享剪贴板
autocmd Filetype c setlocal makeprg=gcc\ -Wall\ -O2\ -std=c99\ \ % "make时执行的编译命令
set autowrite "自动保存
set ignorecase "搜索忽略大小写
set iskeyword+=_,$,@,%,#,- "带有如下符号的单词不要被换行分割
set backspace=2 "使回格键（backspace）正常处理indent, eol, start等
set autoread "pyth设置当文件被改动时自动载入
set wrap "自动折行
set textwidth=80 "自动换行
set fo+=m "一个汉字作为两个字符计算换行

filetype plugin indent on "根据文件类型智能载入插件、缩进
let g:acp_completeoptPreview = 1 "在ACP自动补全时显示文档

"让Vim的补全菜单行为与一般IDE一致(参考VimTip1228)
set completeopt+=longest "离开插入模式后自动关闭预览窗口
autocmd InsertLeave * if pumvisible() == 0|pclose|endif
"回车即选中当前项
inoremap <expr> <CR>       pumvisible() ? "\<C-y>" : "\<CR>"
"上下左右键的行为
inoremap <expr> <Down>     pumvisible() ? "\<C-n>" : "\<Down>"
inoremap <expr> <Up>       pumvisible() ? "\<C-p>" : "\<Up>"
inoremap <expr> <PageDown> pumvisible() ? "\<PageDown>\<C-p>\<C-n>" : "\<PageDown>"
inoremap <expr> <PageUp>   pumvisible() ? "\<PageUp>\<C-p>\<C-n>" : "\<PageUp>"

"针对Python的制表符替换，不再使用
"autocmd FileType python setlocal et sta sw=4 sts=4
"如有需要，可设置忽略部分PEP8错误 let g:flake8_ignore="E501"

"所有信息、编码一律为简体中文，UTF-8，并避免乱码
set encoding=utf-8
set fileencodings=utf-8,ucs-bom,shift-jis,gb18030,gbk,gb2312,cp936
set langmenu=zh_CN.UTF-8
language message zh_CN.UTF-8
"解决菜单乱码
source $VIMRUNTIME/delmenu.vim
source $VIMRUNTIME/menu.vim

set nu "启用行号
"设置字体，已弃用
"set guifont=Courier_new:h11

"针对LaTeX的配置
set grepprg=grep\ -nH\ $*
let g:tex_flavor='latex'


func! Run16encoding()
    "进行16进制转储
        exec "%!xxd"
endfunc
 
func! Run16decoding()
    "将16进制解码
        exec "%!xxd -r"
endfunc

func! CompileAndRun()
    exec "w"
    if &filetype == 'c'
        exec "!gcc % -o %.bin -O2 -std=c99"
        exec "! ./%.bin"
    elseif &filetype == 'cpp'
        exec "!g++ % -o %.bin"
        exec "! ./%.bin"
    elseif &filetype == 'java' 
        exec "!javac %" 
        exec "!java %<"
    elseif &filetype == 'sh'
        :!./%
    elseif &filetype == 'python'
        exec "!python2 %"
    elseif &filetype == 'html'
        exec "!chromium % &"
    endif
endfunc`

func! CompileAndDebugC()
    exec "w"
    if &filetype == 'c'
        exec "!gcc % -o %.bin -g -std=c99"
        exec "!gdb ./%.bin"
    elseif &filetype == 'cpp'
        exec "!g++ % -o %.bin -g"
        exec "!gdb ./%.bin"
    endif
endfunc

map <F4> :call CompileAndDebugC()<CR>
map <F5> :call CompileAndRun()<CR>
"<F7> :call Flake8()
map <F9> :call Run16encoding()<CR>
map <F10> :call Run16decoding()<CR>
