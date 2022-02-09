# Branching System

## Commit Style 

In order to achieve a uniform naming for commit messages the following **commit style** should be used when creating a new commit message. 

| Keyword | Description                                                                                                                                                                                     |
| ------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| ADD     | Is used if there is a new change in the code. **f.e** `git commit -m "ADD function XY()"`                                                                                                       |
| FIX     | Used for minor changes, bugfixes of an already existing part of the code. **f.e** `git commit -m "FIX functionality of XY"`                                                                     |
| REF     | Written short for: REFACTOR. Is used when there is a major change in multiple code-segments and the structure of the code is reworked. **f.e** `git commit -m "UPDATE setup of analog sensors"` |

[^1]: source: [https://codeburst.io/git-and-github-in-a-nutshell-b0a3cc06458f](https://codeburst.io/git-and-github-in-a-nutshell-b0a3cc06458f)

## Creating Pull Requests

In order to keep the `master`branch clean and functioning the prototyping repository has a **branch protection rule**. When someone wants to merge code onto the `master` branche a **pull request** has to be made. The **pull request** informs the `admin` of the repository to have a look over the code in order to approve if this its functioning and good code which can be merged without hesitation. In order to understand how to create a **pull request** have a look [here](https://www.digitalocean.com/community/tutorials/how-to-create-a-pull-request-on-github)