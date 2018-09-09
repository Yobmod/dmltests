from django.urls import path
from .views import (home,
                    compress_html,
                    compress_jinja,
                    pipeline_html,
                    pipeline_jinja,
                    )

app_name = 'main'

urlpatterns = [
    path('', home, name='home'),
    path('comp/', compress_html, name='compress'),
    path('pipe/', pipeline_jinja, name='pipeline'),

]
