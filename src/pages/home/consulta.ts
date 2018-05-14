import { Injectable } from '@angular/core';
import 'rxjs/add/operator/map';
import { HttpClient } from '@angular/common/http';

@Injectable()
export class ConsultaProvider {

    constructor(public http: HttpClient){
    }

    isAuto(auto){
        
        if(auto == true){
            auto= 1;
        }else{
            auto= 0
        }
        console.log(auto)
       return this.http.get(`http://201.6.243.44:3035/api?sensorName=IoTPLModo&data=${auto}`)
    }

    mandaLuz(luz){
        console.log(luz)
        return this.http.get(`http://201.6.243.44:3035/api?sensorName=IoTPLLux&data=${luz}`)
    }
}