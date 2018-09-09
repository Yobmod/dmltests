from django.shortcuts import render
from django.http import HttpResponse


def home(request):
    return HttpResponse('Home')


def compress_html(request):
    return render(request, 'compress.html')


def pipeline_html(request):
    return render(request, 'pipeline.html')


def compress_jinja(request):
    return render(request, 'compress.jinja')


def pipeline_jinja(request):
    return render(request, 'pipeline.jinja')
