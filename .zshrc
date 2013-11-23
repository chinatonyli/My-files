ZSH="/home/biergaizi/.oh-my-zsh"
ZSH_THEME="gaizi"
CASE_SENSITIVE="true"
DISABLE_AUTO_UPDATE="true"
# DISABLE_UNTRACKED_FILES_DIRTY="true"
plugins=(git gnu-utils github)
source $ZSH/oh-my-zsh.sh

HISTFILE=~/.histfile
HISTSIZE=100000000
SAVEHIST=1000000000000000000
setopt hist_ignore_space
setopt SHARE_HISTORY

limit coredumpsize 0

PATH="/usr/lib64/ccache/bin:$PATH"

alias cp='cp -i'
alias mv='mv -i'
alias rm='rm -i'
alias ls='ls -F --color=auto'
alias ll='ls -l'
alias grep='grep --color=auto'
alias lazy-sync='sudo su -c "emerge --sync; layman -S; emerge -uvDN --pretend world"'
alias lazy-upgrade='sudo su -c "emerge -u portage; emerge -uvDN world --keep-going"'
alias lazy-clean='sudo su -c "emerge @preserved-rebuild; emerge --depclean; revdep-rebuild"'
alias top10='print -l ${(o)history%% *} | uniq -c | sort -nr | head -n 10'
alias gfw='ssh ubuntu@ec2-54-238-107-191.ap-northeast-1.compute.amazonaws.com -D 7070'

# Execute a screen when I login with a TTY
TTY=$(tty)
if [[ ! $TTY =~ 'pts' ]]
then
  exec screen
fi
