# Stone-Keeper
game engine

step 1: update changes and create a branch
git checkout main              # Switch to main
git pull                       # Update local main
git checkout -b branch_name  # Create and switch to new branch

Step 2: Make Changes and Commit
• Work on your branch.
• Make small, focused commits.
• Use meaningful commit messages.
Example: Fix navbar layout

Commands to stage, commit, and push changes

git add .                                # Stage changes
git commit -m "Describe your change"     # Commit with message
git push origin branch_name            # Push branch to GitHub

Step 3: Open a Pull Request
1. Push your branch to GitHub.
2. Go to the repository page.
3. Click Compare & pull request.
4. Add a description of your changes.
5. Select main as the target branch.
6. Merge

Merge the Pull Request on GitHub:
• Click Merge pull request.
• Optionally delete the branch after merging (see below).

Step 4: Delete Branch After Merge

Delete local branch:

git branch -d branch_name

Delete remote branch:

git push origin --delete branch_name