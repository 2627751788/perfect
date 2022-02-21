//于2022年2月20日，开始使用git，用于记录自己的学习过程

1.git的安装及使用
https://www.liaoxuefeng.com/wiki/896043488029600
2.选择下载Windows的安装包
3.下载git包后，无法安装
需要下载wget	GNU Wget 1.21.2 for Windows (eternallybored.org)
下载后就可以打开git bash
4.配置git
git config --global user.name "Your Name"
git config --global user.email "email@example.com"
5.git基础指令的使用
git init 	//将这个目录变成可git管理的目录（可以cd进想要的路径下去创建文件夹）
ls -ah		//查看隐藏的目录

文件添加到git仓库的两步骤如下：
git add		//将文件添加到仓库			实际是将文件添加到暂存区
git commit -m "xxx"	//添加提交说明		实际是将文件放到本地的master分支

git status	//查看当前仓库的状态（有文件修改，无文件修改）
git diff	//查看当前修改的文件与源文件的不同之处

git log		//查看每一次commit后的历史记录
git reset --hard HEAD^	//回退到上一个修改的版本（HEAD^表示上一个版本，HEAD^^表示上上个版本，HEAD~100表示上100个版本）
git reset --hard commit值	//表示回退到指定的commit
注意：若是使用git reset --hard HEAD^回退到上一个版本之后，需要知道上一个版本的commit值，才可以使用命令git reset --hard commit值回去
git reflog	//可查看历史命令

git diff HEAD -- 修改的文件名	//查看当前修改的工作区和版本库里的区别

小知识：
第一次修改->git add->第二次修改->git add	//将两次修改合并

git checkout --文件名	//将文件在工作区的修改全部撤销
git reset HEAD 文件名	//将暂存区的东西，重新放回工作区


git rm 文件名	//将版本库中的文件删除






