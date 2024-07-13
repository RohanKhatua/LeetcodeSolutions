from typing import List
from collections import Counter

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        # for each time period we have a list of allowed tasks
        # rather a list of prevented tasks
        # if the currently pending task is not allowed we have to wait for it to be allowed
        # as soon as the time is past we delete to clean up memory
        # tasks can be done in any order
        # at every point in time pick an available task which is permitted
        # after doing a task that task becomes not allowed till curr_time+n
        # maintain a dict of when a task is allowed again
        # update it when that time arrives
        # find a task somehow
        # first find how many times we have to do each task
        # all jobs have equal cooldown times
        # so the names of the jobs dont matter
        
        # curr task should be incremented if - 
        # 1. a task was performed
        # 2. we looked through all tasks and none were eligible

        total_tasks = dict(Counter(tasks))
        tasks_left = total_tasks.copy()

        allowed_at = {}
        curr_time = 0

        while (tasks_left):
            didatask = False
            for task_name, num_tasks in total_tasks.items():
                if (task_name not in allowed_at) or (allowed_at[task_name] >= curr_time):
                #    we can perform the task
                    tasks_left[task_name] -=1
                    allowed_at[task_name] = curr_time + n
                    if tasks_left[task_name] == 0:
                        del tasks_left[task_name]
                    curr_time +=1
                    didatask = True
                    # if you do a task, just go to the next iteration
                    continue                 
            
                if not tasks_left:
                    break
            if not didatask:
                curr_time +=1
            
        return curr_time
    
s = Solution()
print (s.leastInterval(["A","A","A", "B","B","B"], 3))


        
        

