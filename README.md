# Stone-Keeper
game engine

//Create and switch to new branch
git checkout -b branch_name

// add, commit and push your changes to GitHub
git add .
git commit -m "Describe your change"
git push origin branch_name 

//merge with main and delete the branch
gh pr create --base main --head branch_name --fill
gh pr merge --merge --delete-branch
git checkout main
git pull
