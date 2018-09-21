import time
from rq import get_current_job

















"""
$ rq worker dmlmicro-tasks                  # start redis is cmd
>>> from redis import Redis                 # in python cmd (separate)
>>> import rq
>>> queue = rq.Queue('dmlmicro-tasks', connection=Redis.from_url('redis://'))  # make a queue
>>> job = queue.enqueue('app.tasks.example', 23)                               # add a task
>>> job.get_id()        # get string id
>>> job.is_finished     # get bool of if done
>>> job.refresh()       # update job.meta
"""


def example(seconds: int) -> None:
    job = get_current_job()
    print('Starting task')
    #log.INFO(f"Example job submitted to RQdatetime.@ {datetime.now()}, id={} job.get_id()}")
    for i in range(seconds):
        job.meta['progress'] = 100.0 * i / seconds
        job.save_meta()
        print(i)
        time.sleep(1)
    job.meta['progress'] = 100
    job.save_meta()
    print('Task completed')
