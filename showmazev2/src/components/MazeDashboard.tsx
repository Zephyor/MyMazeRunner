import React, { useState } from 'react';
import './MazeDashboard.css';
import MazeMap from './MazeMap';


const MazeDashboard = () => {
    
    const [selectedFiles, setSelectedFiles] = useState<string[]>([]);
 
    const handleFileChange = (event: any) => {
        const file = event.target.files[0];
        console.log(event.target.files);
        const reader = new FileReader();
        reader.onload = ((evt: ProgressEvent<FileReader>) => {
            console.log(evt.target?.result);
            if (evt.target?.result !== null) {
                setSelectedFiles([...selectedFiles, evt.target?.result as string]);
            }
        });
        reader.readAsText(file);
    }

    return (
        <div className='container'>
            <div className='card'>   
                <div className='file-selector'>
                    <input type='file' onChange={handleFileChange}/>
                </div>
                <div className="maze-dashboard">
                    {selectedFiles.map((filename) => { 
                        return <MazeMap content={filename} />;
                     })}
                </div>
            </div>
        </div>
    );
}

export default MazeDashboard;